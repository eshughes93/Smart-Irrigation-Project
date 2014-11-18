#include <iostream>

#include "../generic_data_stream.h"
#include "../array_data_stream.h"

using namespace std;

typedef int DataType;

// Use f(x) = x as a testing function. This way, the value in the array 
// is also the index (or would be if the array was big enough).
DataType fu (DataType x) { return x; }

void read_back_all(DataStream<DataType>* data) {
  int data_count = data->get_data_count();
  cout << "Reading back all " << data_count << " datum using get_data." << endl;
  for (DataType i=0; i < data_count; i++) {
    cout << "Index [" << i << "] = " << data->get_data(i) << endl;
  }
}

void test_ArrayDataStream () {
  // Testing the ArrayDataStream

  int max = 10;
  DataType x = 0; // fu(x) will be filling the array.
  DataStream<DataType>* data = new ArrayDataStream<DataType>(max);

  cout << "Array max_length = " << data->get_max_length() << endl;

	cout << "Empty data cell = " << data->get_last_data() << endl;

  // Partially fill the array. Test out the datum getter functions.
  cout << "Creating " << max-1 << " data points in the array using add_data." << endl;
  for (; x < max-1; x++) { data->add_data(fu(x)); }
  cout << "Last data using get_last_data: " << data->get_last_data() << endl;
  read_back_all(data);
  cout << endl;

  // Fill the array
  cout << "Adding the last data point to fill the array using add_data." << endl;
  data->add_data(fu(x++));
  cout << "Last data using get_last_data: " << data->get_last_data() << endl;
  read_back_all(data);
  cout << endl;

  // Start overwriting data by adding another datum.
  cout << "Adding and extra data point using add_data (begin overwriting)." << endl;
  data->add_data(fu(x++));
  cout << "Last data using get_last_data: " << data->get_last_data() << endl;
  read_back_all(data);
  cout << endl;

  // Completely overwrite the array twice. 
  cout << "Creating " << 2*max-1 << " more data points in the array using add_data." << endl;
  cout << "The array should be filled with " << fu(2*max) << " to " << fu(3*max-1) << endl;
  for (; x < (3*max); x++) { data->add_data(fu(x)); }
  read_back_all(data);
}

int main() {
  test_ArrayDataStream();
}

