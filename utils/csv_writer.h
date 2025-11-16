#ifndef CSV_WRITER_H
#define CSV_WRITER_H

#include <string>
#include <vector>
#include <fstream>

class csv_writer {
private:
	std::ofstream file;
	bool first_in_row;

public:
	csv_writer(const std::string& filename);
	~csv_writer();

	void write_row(const std::vector<double>& data);
	void write_header(const std::vector<std::string>& headers);
	void close();
};

#endif
