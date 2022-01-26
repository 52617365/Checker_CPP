
#ifndef OUT_STREAMS_H
#define OUT_STREAMS_H
#include <fstream>

#include "filestreams.h"


/**
  * class out_streams
  * 
  */

class out_streams : filestreams
{
protected:

	using filestreams::filestreams;
	void write_file();
	void operator <<(std::fstream& fs, out_streams& out);
};
#endif // OUT_STREAMS_H
