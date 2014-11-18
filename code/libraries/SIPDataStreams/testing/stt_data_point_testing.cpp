#include <iostream>
#include <iomanip>

#include "../generic_data_stream.h"
#include "../array_data_stream.h"
#include "../stt_data_point.h"

using namespace std;

typedef float SaturationType;
typedef float TemperatureType;
typedef int TimestampType;

typedef STTDataPoint<SaturationType, TemperatureType, TimestampType>* DataTypePt;

// Use fu(x) = x as a testing function. This way, the value in the 
// array is also the index (or would be if the array was big enough).
int fu (int x) { return x; }

DataTypePt new_data (int x) {
  return new STTDataPoint<SaturationType,
                          TemperatureType,
                          TimestampType>
                          (float(x)/(x+1), x*x, fu(x));
}

void print_datum(DataTypePt datum) {
  SaturationType sat = datum->get_saturation();
  TemperatureType temp = datum->get_temperature();
  TimestampType time = datum->get_timestamp();

  cout << "Saturation = " << setprecision(2) << fixed << sat;
  cout << ", Temperature = " << temp;
  cout << ", Time = " << time;
}


void read_back_all(DataStream<DataTypePt>* data) {
  int data_count = data->get_data_count();
  cout << "Reading back all " << data_count << " datum using get_data." << endl;
  for (int i=0; i < data_count; i++) {
    cout << "Index [" << i << "]: ";
		print_datum(data->get_data(i));
		cout << endl;
  }
}

void read_last_datum(DataStream<DataTypePt>* data) {
  cout << "Last data using get_last_data: ";
	print_datum(data->get_last_data());
	cout << endl;
}

void test_ArrayDataStream () {
  // Testing the ArrayDataStream

  int max = 10;
  int x = 0; // new_data(x) will be filling the array.
  DataStream<DataTypePt>* data = new ArrayDataStream<DataTypePt>(max);

  cout << "Array max_length = " << data->get_max_length() << endl;

	//cout << "Empty data cell = ";
	//print_datum(data->get_last_data());
	//cout << endl;

  // Partially fill the array. Test out the datum getter functions.
  cout << "Creating " << max-1 << " data points in the array using add_data." << endl;
  for (; x < max-1; x++) { data->add_data(new_data(x)); }
	read_last_datum(data);
  read_back_all(data);
  cout << endl;

  // Fill the array
  cout << "Adding the last data point to fill the array using add_data." << endl;
  data->add_data(new_data(x++));
	read_last_datum(data);
  read_back_all(data);
  cout << endl;

  // Start overwriting data by adding another datum.
  cout << "Adding and extra data point using add_data (begin overwriting)." << endl;
  data->add_data(new_data(x++));
	read_last_datum(data);
  read_back_all(data);
  cout << endl;

  // Completely overwrite the array twice. 
  cout << "Creating " << 2*max-1 << " more data points in the array using add_data." << endl;
  cout << "The array should contain the sequence " << fu(2*max) << " to " << fu(3*max-1) << endl;
  for (; x < (3*max); x++) { data->add_data(new_data(x)); }
  read_back_all(data);
}

int main() {
  test_ArrayDataStream();
}

