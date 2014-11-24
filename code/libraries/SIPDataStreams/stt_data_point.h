#ifndef DATA_POINT_H
#define DATA_POINT_H

// Adding back into the repository...

/* 
 * STTDataPoint is a simple template container for saturation, 
 * temperature, and timestamp values (STT). This class is templated 
 * because, at the time of writing, I don't know what the types will be 
 * and I don't know if I would want to restrict the type anyway.
 *
 * This class is intended for use as the DataType in the DataStream 
 * classes.
 *
 */

template <class SaturationType, class TemperatureType, class TimestampType>
class STTDataPoint {
	private:
    SaturationType m_saturation;
		TemperatureType m_temperature;
		TimestampType m_timestamp;
	
	public:
		STTDataPoint(SaturationType saturation,
				      TemperatureType temperature,
				      TimestampType timestamp) {
			m_saturation = saturation;
			m_temperature = temperature;
			m_timestamp = timestamp;
		}
		SaturationType get_saturation() { return m_saturation; }
		TemperatureType get_temperature() { return m_temperature; }
		TimestampType get_timestamp() { return m_timestamp; }

		void set_saturation(SaturationType new_value) { m_saturation = new_value; }
		void set_temperature(TemperatureType new_value) { m_temperature = new_value; }
		void set_timestamp(TimestampType new_value) { m_timestamp = new_value; }
};

#endif
