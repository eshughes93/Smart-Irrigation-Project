#include <Arduino.h>
#include "data_streams.h"
#include "generic_data_stream.h"


/*** ArrayDataStream functions ***/
template <class DataType>
ArrayDataStream::ArrayDataStream(int max_length) : DataStream() {
	m_next_index = 0;
	m_overwriting = false;
	m_max_length = max_length;
	m_data_array = new DataType[max_length];
}

template <class DataType>
void ArrayDataStream::add_data(DataType new_data){
	// Add data to the data array
  if (m_next_index < m_max_length) {
		// Next index is within bounds of the array.
    m_data[m_next_index] = new_data;
    m_next_index++;

		if (m_next_index == m_max_length) {
			// Array is full, start overwriting old data...
			m_next_index = 0;
			m_overwriting = true;
		}
}

template <class DataType>
DataType ArrayDataStream::get_last_data(){
	// Return the most recently created data point.
	if (0 == m_next_index) {
		return m_data_array[m_max_length - 1];
	} else {
		return m_data_array[m_next_index - 1];
}

template <class DataType>
DataType ArrayDataStream::get_data(int index){
	if (0 <= index && index < m_max_length) {
		// Index is within bounds.
		return m_data_array[index];
	} else {
		//
		///// Index out of bounds... What to do? Throw error? /////
		//
		return m_data_array[0];
	}
}

int ArrayDataStream::get_count(){
	if (m_overwriting){
		// Maximum number of data being stored.
		return m_max_length;
	} else {
		// m_next_index happens to also be the number of data points stored 
		// in the partially filled array.
		return m_next_index;
	}
}

int ArrayDataStream::get_max_length(){
	return m_max_length;
}

/*** End ArrayDataStream functions ***/
