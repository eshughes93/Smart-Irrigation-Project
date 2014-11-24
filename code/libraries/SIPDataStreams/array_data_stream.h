#ifndef DATA_STREAMS_H
#define DATA_STREAMS_H

#include "generic_data_stream.h"

/* ArrayDataStream is a type of data stream which uses an array to 
 * store the data. Ideally, the benefit of using a simple array is that 
 * it hopefully will use less memory than other containers. The array 
 * size is given at construction time. Making ArrayDataStream a 
 * template allows for any type of value to be stored in the array.
 *
 * Due to some funkiness with template classes, I either have to 
 * hardcode the template types at the bottom of the .cpp file or have 
 * all definitions in this file. Hardcoding the types worked initially, 
 * but stopped for an unknown reason. Writing the definitions in this 
 * file seems to be working at the moment.
 */

template<typename DataType>
class ArrayDataStream : public DataStream<DataType> {
  private:
    int m_next_index;
    bool m_overwriting;
    int m_max_length;
    DataType* m_data_array;

		void increment_next_index();

  public:
    ArrayDataStream(int max_length);

    DataType add_data(DataType new_data); // Returns old datum to be destroyed.
    DataType manually_update_next(); // Returns the datum to be updated. Only useful if it is a pointer.
    DataType get_last_data();
    DataType get_data(int index_from_oldest);

    int get_data_count();
    int get_max_length();
};

#endif


template <class DataType>
ArrayDataStream<DataType>::ArrayDataStream(int max_length):
  DataStream<DataType>()
{
  m_next_index = 0;
  m_overwriting = false;
  m_max_length = max_length;
  m_data_array = new DataType[max_length];
}

template <class DataType>
DataType ArrayDataStream<DataType>::add_data(DataType new_data){
	// Add a new datum to the data array. Returns the old datum to be 
	// destroyed; does not check if the value is empty or not.
	//
	// While there are (convoluted) ways of figuring out if the template 
	// variable is a pointer rather than a basic data type (int, float, 
	// etc.), there is no way to know how the variable was created. 
	// Therefore we don't know how the pointer should be deleted.
  //
	// Note, m_next_index will be less than m_max_length. No need to 
	// check that this is true.

	// Save the old value...
	DataType old_datum = m_data_array[m_next_index]; 

	// Next index is within bounds of the array. Add new data here.
	m_data_array[m_next_index] = new_data;

	// Move the next_index
	increment_next_index();
	
	// Return the old datum for deleting.
	return old_datum;
}

template <class DataType>
DataType ArrayDataStream<DataType>::manually_update_next(){
	// Returns the oldest datum so it can be updated rather than adding a 
	// new object to the array. The next index will be moved down the 
	// array.
	//
	// This is only useful if the DataType is a pointer.
	//
	// Note, m_next_index will be less than m_max_length. No need to 
	// check that this is true.

	// Save the old value...
	DataType old_datum = m_data_array[m_next_index]; 

	// Move the next_index
	increment_next_index();

	// Return the old datum for updating.
	return old_datum;
}

template <class DataType>
void ArrayDataStream<DataType>::increment_next_index(){
	m_next_index++;
	if (m_next_index == m_max_length) {
		// Array is full, start overwriting old data...
		m_next_index = 0;
		m_overwriting = true;
	}
}
	

template <class DataType>
DataType ArrayDataStream<DataType>::get_last_data(){
  // Return the most recently created data point.
  if (0 == m_next_index) {
    return m_data_array[m_max_length - 1];
  } else {
    return m_data_array[m_next_index - 1];
  }
}

template <class DataType>
DataType ArrayDataStream<DataType>::get_data(int index_from_oldest){
  // Return a specific value where the given index is measured from the 
  // oldest item in the list. Negative values will wrap around.
  int oldest_index = (m_overwriting)? m_next_index : 0;
  int data_count = (m_overwriting)? m_max_length : m_next_index;
  
  // In case they gave a negative index_from_oldest, wrap the negative 
  // values around to the end of the data set to create a positive 
  // index offset. Will still work even if the array is not full.
  if (index_from_oldest < 0) {
    index_from_oldest = m_max_length + index_from_oldest % data_count;
  }

  // Add the desired index offset to the index of the oldest datum.  
  // Wrap around if the index is out of bounds.
  int index = (index_from_oldest + oldest_index) % m_max_length;

  return m_data_array[index];
}

template <class DataType>
int ArrayDataStream<DataType>::get_data_count(){
  if (m_overwriting){
    // Maximum number of data being stored.
    return m_max_length;
  } else {
    // m_next_index happens to also be the number of data points stored 
    // in the partially filled array.
    return m_next_index;
  }
}

template <class DataType>
int ArrayDataStream<DataType>::get_max_length(){
  return m_max_length;
}
