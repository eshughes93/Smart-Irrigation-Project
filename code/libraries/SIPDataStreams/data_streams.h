#ifndef DATA_STREAMS_H
#define DATA_STREAMS_H

#include "generic_data_stream.h"

/* ArrayDataStream is a type of data stream which uses an array to 
 * store the data. Ideally, the benefit of using a simple array is that 
 * it hopefully will use less memory than other containers. The array 
 * size is given at construction time. Making ArrayDataStream a 
 * template allows for any type of value to be stored in the array.
 */

template<typename DataType>
class ArrayDataStream : public DataStream<DataType> {
  private:
    int m_next_index;
    bool m_overwriting;
    int m_max_length;
    DataType* m_data_array;

  public:
    ArrayDataStream(int max_length);

    void add_data(DataType new_data);
    DataType get_last_data();
    DataType get_data(int index_from_oldest);

    int get_data_count();
    int get_max_length();
};

// Linked list .....

#endif
