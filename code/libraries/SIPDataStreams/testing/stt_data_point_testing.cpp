#include <iostream>
#include <iomanip>

#include "../generic_data_stream.h"
#include "../array_data_stream.h"
#include "../stt_data_point.h"

using namespace std;

typedef float SaturationType;
typedef float TemperatureType;
typedef int TimestampType;

typedef STTDataPoint<SaturationType, TemperatureType, TimestampType>* DataTypePtr;

// Use fu(x) = x as a testing function. This way, the value in the 
// array is also the index (or would be if the array was big enough).
int fu (int x) { return x; }

DataTypePtr new_data (int x) {
  return new STTDataPoint<SaturationType,
                          TemperatureType,
                          TimestampType>
                          (float(x)/(x+1), x*x, fu(x));
}


DataStream<DataTypePtr>* create_datastream (int max){
	DataStream<DataTypePtr>* data = new ArrayDataStream<DataTypePtr>(max);
  for (int i=0;  i<max; i++){
    DataTypePtr new_datum = new STTDataPoint<SaturationType,
																						 TemperatureType,
																						 TimestampType>
																						(0,0,0);
    data->add_data(new_datum);
  }

	return data;
}
void add_data(DataStream<DataTypePtr>* data, DataTypePtr datum) {
	// This testing file specifies the data type as a pointer, therefore, 
	// we need to delete the old datum returned by data->add_data. The 
	// delete operation should have no effect if old_datum is a null 
	// pointer.
	//DataTypePtr old_datum = data->add_data(datum);
	//delete old_datum;
	DataTypePtr old_datum = data->manually_update_next();
	old_datum->set_saturation(datum->get_saturation());
	old_datum->set_temperature(datum->get_temperature());
	old_datum->set_timestamp(datum->get_timestamp());
	delete datum;
}

void print_datum(DataTypePtr datum) {
	// Print a particular STT datum.
  SaturationType sat = datum->get_saturation();
  TemperatureType temp = datum->get_temperature();
  TimestampType time = datum->get_timestamp();

	cout << setprecision(2) << fixed; // format float output
  cout << "Saturation = " << sat;
  cout << ", Temperature = " << temp;
  cout << ", Time = " << time;
}


void read_back_all(DataStream<DataTypePtr>* data) {
	// Print the contents of the given data stream
  int data_count = data->get_data_count();
  cout << "Reading back all " << data_count << " datum using get_data." << endl;
  for (int i=0; i < data_count; i++) {
    cout << "Index [" << i << "]: ";
		print_datum(data->get_data(i));
		cout << endl;
  }
}

void read_last_datum(DataStream<DataTypePtr>* data) {
  cout << "Last data using get_last_data: ";
	print_datum(data->get_last_data());
	cout << endl;
}

void test_ArrayDataStream () {
  // Testing the ArrayDataStream

  int max = 10;
  int x = 0; // new_data(x) will be filling the array.
  DataStream<DataTypePtr>* data = create_datastream(max);

  cout << "Array max_length = " << data->get_max_length() << endl;

	//cout << "Empty data cell = ";
	//print_datum(data->get_last_data());
	//cout << endl;

  // Partially fill the array. Test out the datum getter functions.
  cout << "Creating " << max-1 << " data points in the array using add_data." << endl;
  for (; x < max-1; x++) { add_data(data, new_data(x)); }
	read_last_datum(data);
  read_back_all(data);
  cout << endl;

  // Fill the array
  cout << "Adding the last data point to fill the array using add_data." << endl;
  add_data(data, new_data(x++));
	read_last_datum(data);
  read_back_all(data);
  cout << endl;

  // Start overwriting data by adding another datum.
  cout << "Adding and extra data point using add_data (begin overwriting)." << endl;
  add_data(data, new_data(x++));
	read_last_datum(data);
  read_back_all(data);
  cout << endl;

  // Completely overwrite the array twice. 
  cout << "Creating " << 2*max-1 << " more data points in the array using add_data." << endl;
  cout << "The array should contain the sequence " << fu(2*max) << " to " << fu(3*max-1) << endl;
  for (; x < (3*max); x++) { add_data(data, new_data(x)); }
  read_back_all(data);
}

int main() {
  test_ArrayDataStream();
}

