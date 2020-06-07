#ifndef DATABUFFER_H
#define DATABUFFER_H

#include "std_include.h"
#include "Logger.h"
#include <type_traits>
#include <assert.h>

using namespace std;

template<typename T>
class DataBuffer{
public:

    // Constructor
    DataBuffer() {};
    // Copy Constructor
    DataBuffer(const DataBuffer<T> &other) { data = other.data; };
    // Constructor with data vector initialisation
    DataBuffer(vector<T> dat) : data(dat) {};
    // Constructor with data array initialisation
    DataBuffer(T *dat, int size);

    // Copy operator
    DataBuffer<T>& operator=(const DataBuffer<T> &other) { data = other.data; return *this; };
    // Destructor
    virtual ~DataBuffer() = default;

    // Clears data from buffer
    void clear();

    // Transforms the data buffer into a string
    virtual string toString();

    // Size of the buffer
    int size() { return data.size(); };
    // Size of data between cursor and buffer's end 
    int remainingDataSize() { return size() - cursor; }
    // True if the cursor is at the end of the buffer
    bool isExhausted() { return cursor >= size(); };
    

    // Gets cursor position
    int get_cursor() { return cursor; };

    // Moves the cursor by offset on the right. Offset can be negative. Safeguarded
    bool cursor_move(int offset);
    // Moves the cursor by 1 on the right. Safeguarded
    bool cursor_increment();
    // Moves the cursor by 1 on the left. Safeguarded
    bool cursor_decrement();

    // Sets the cursor position. Safeguarded
    bool cursor_set(int pos);
    // Sets the cursor at the beginning of the buffer
    void cursor_reset() { cursor = 0; };
    // Sets the cursor at the just before the end of the buffer. 
    // Valid position for reading and writing
    void cursor_readEnd() { cursor = size() - 1; }
    // Sets the cursor beyond the end of the buffer
    // Position to write data after the buffer
    // Valid position to write but invalid position to read
    void cursor_end() { cursor = size(); };
    
    // Reads one unit of data
    T read();
    // Reads n units of data
    vector<T> read(int n);
    // Reads all data
    vector<T> read_all() { return data; }

    // Writes data on the right of the cursor
    void write(T dat);
    // Writes data on the right of the cursor
    void write(vector<T> dat);

    // Insert data space on the right of the cursor
    void insertDataSpace(int n);

    // Pushes data at the end of the buffer
    void push(T dat) { data.push_back(dat); };
    // Pushes data at the end of the buffer
    void push(vector<T> dat) { data.insert(data.end(), dat.begin(), dat.end()); };
    // Pushes data at the end of the buffer
    void push(T *dat, int length) { data.insert(data.end(), dat, dat + length); };

    // Pops one unit of data from the end of the vector. Data is erased
    T pop();
    // Pops n units of data from the end of the vector. Data is erased
    vector<T> pop(int n);

    // Splits DataBuffer from the cursor position to the end. Data is not erased.
    DataBuffer<T> split();
    // Splits DataBuffer from 'index' position to the end. Data is not erased.
    DataBuffer<T> split(int index);
    // Returns a slice of DataBuffer, from index 'beg' to 'end'. Data is not erased.
    DataBuffer<T> slice(int beg, int end);

    // Return the actual data for more complex manipulation.
    // If you modify it, you must be careful of the cursor's position.
    // No verification will be done afterwards.
    vector<T> &getData() { return data; }

protected:

    // Vector containing the actual data
    vector<T> data;

    // Cursor pointing to working data.
    // Moved automatically when accessing/writing data
    // from the cursor position.
    int cursor = 0;
};

template<typename T>
DataBuffer<T>::DataBuffer(T *dat, int size){
    data = vector<T>(dat, dat + size);
}

template<typename T>
void DataBuffer<T>::clear(){
    data.clear();
    cursor = 0;
}

template<typename T>
string DataBuffer<T>::toString(){
    try {

        stringstream str_stream;
        for (T unit : data){
            str_stream << unit << "; ";
        }
        return str_stream.str();

    } catch (exception const& e) {
        Logger::write(e.what(), LOG_DEBUG);
        return "";
    }
}

template<typename T>
bool DataBuffer<T>::cursor_move(int offset){
    if(cursor + offset > size()){
        cursor = size();
        return false;
    } else if(cursor + offset < 0){
        cursor = 0;
        return false;
    }

    cursor += offset;
    return true;
}

template<typename T>
bool DataBuffer<T>::cursor_increment(){
    if((++cursor) >= size()){
        cursor = size();
        return false;
    }

    return true;
}

template<typename T>
bool DataBuffer<T>::cursor_decrement(){
    if((--cursor) < 0){
        cursor = 0;
        return false;
    }

    return true;
}

template<typename T>
bool DataBuffer<T>::cursor_set(int pos){
    if (pos > size() || pos < 0)
        return false;

    cursor = pos;
    return true;
}

template<typename T>
T DataBuffer<T>::read(){
    if(cursor >= size() || cursor < 0){
        Logger::write("Trying to read at index \"" + to_string(cursor) + "\" while there is only " + to_string(size()) + " elements in buffer.", LOG_IMPORTANT_WARNING);
    }
    
    T ret = data[cursor];
    cursor_increment();

    return ret;
}

template<typename T>
vector<T> DataBuffer<T>::read(int n){
    vector<T> ret;
    if (n < 0 || cursor + n - 1 >= size() || cursor + n - 1 < 0){
        Logger::write("Trying to read at index \"" + to_string(cursor + n - 1) + "\" while there is only " + to_string(size()) + " elements in buffer.", LOG_IMPORTANT_WARNING);
        return ret;
    }

    for (int i = 0; i < n; i++){
        ret.push_back(data[cursor]);
        cursor_increment();
    }

    return ret;
}

template<typename T>
void DataBuffer<T>::write(T dat){
    assert (cursor >= 0);

    if(cursor >= size()){
        data.push_back(dat);
    } else {
        data[cursor] = dat;
    }

    cursor_increment();
}

template<typename T>
void DataBuffer<T>::write(vector<T> dat){
    for (T d : dat)
        write(d);
}

template<typename T>
void DataBuffer<T>::insertDataSpace(int n){
    if(n < 0){
        Logger::write("Cannot insert negative ammount of data space.", LOG_WARNING);
        return;
    }

    vector<T> inData(n, 0);
    data.insert(data.begin() + cursor, inData.begin(), inData.end());
    return;
}

template<typename T>
T DataBuffer<T>::pop(){
    if(size() == 0) 
        Logger::write("Cannot pop an empty buffer.", LOG_WARNING);

    T ret = data.end()[-1];
    data.pop_back();

    return ret;
}

template<typename T>
vector<T> DataBuffer<T>::pop(int n){
    if(n < 0)
        Logger::write("Cannot pop a negative amount of data.", LOG_WARNING);

    vector<T> ret;
    
    for(int i = 0; i < n; i++)
        ret.push_back(pop());
    
    return ret;
}

template<typename T>
DataBuffer<T> DataBuffer<T>::split(){
    vector<T> ret_data(data.begin() + cursor, data.end());

    return DataBuffer<T>(ret_data);
}

template<typename T>
DataBuffer<T> DataBuffer<T>::split(int index){
    if(index > size() || index < 0){
        Logger::write("Cannot split at index \"" + to_string(index) + "\", there is only " + to_string(size()) + " elements in the buffer.", LOG_IMPORTANT_WARNING);
        return DataBuffer<T>();
    }
    

    try {
        vector<T> ret_data(data.begin() + index, data.end());

        return DataBuffer<T>(ret_data);
    } catch (exception e) {
        Logger::write("Error on DataBuffer split : " + (string) e.what(), LOG_ERROR);
        return DataBuffer<T>();
    }
}

template<typename T>
DataBuffer<T> DataBuffer<T>::slice(int beg, int end){
    if(beg > end)
        Logger::write("Cannot make a split : beginning (" + to_string(beg) + ") is greater than end (" + to_string(end) + ").", LOG_IMPORTANT_WARNING);
    if(beg > size() || beg < 0)
        Logger::write("Cannot begin slice at index \"" + to_string(beg) + "\", there is only " + to_string(size()) + " elements in the buffer.", LOG_IMPORTANT_WARNING);
    if(end > size() || end < 0)
        Logger::write("Cannot end slice at index \"" + to_string(end) + "\", there is only " + to_string(size()) + " elements in the buffer.", LOG_IMPORTANT_WARNING);

    try {
        vector<T> ret_data(data.begin() + beg, data.begin() + end);

        return DataBuffer<T>(ret_data);
    } catch (std::exception const& e){
        Logger::write("Error on DataBuffer slice : " + (string) e.what(), LOG_ERROR);
        return DataBuffer<T>();
    }
}

#endif