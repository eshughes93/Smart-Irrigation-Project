#ifndef GENERIC_DATA_STREAM_H
#define GENERIC_DATA_STREAM_H

/* DataStream is an templated abstract base class meant to create a 
 * common interface.  Derived classes will define a particular way to 
 * store data. This class is a template to allow the user to store any 
 * kind of data. However, this limits some of the benefits of being an 
 * abstract base class. For example, DataStream* does not exist and 
 * DataStream<int> is different from DataStream<float>. So there is no 
 * way to refer to a generic DataStream, just a generic 
 * DataStream<type>. The storage technique is hidden by inheritance, 
 * but the data type cannot be hidden.
 *
 * After much research on abstract template classes, I believe it is 
 * impossible to get the functionality I desire. As is, there is no way 
 * to point to an arbitrary instance of DataStream without knowing the 
 * data type.
 */

template<typename DataType>
class DataStream {
  public:
    DataStream() {}
    virtual void add_data(DataType value)=0;
    virtual DataType get_last_data()=0;
    virtual DataType get_data(int index_from_oldest)=0;
    virtual int get_data_count()=0;
    virtual int get_max_length()=0;
};

#endif
