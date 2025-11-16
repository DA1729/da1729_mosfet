#include "csv_writer.h"

csv_writer::csv_writer(const std::string& filename) : first_in_row(true) {
	file.open(filename);
}

csv_writer::~csv_writer() {
	if (file.is_open()) {
		file.close();
	}
}

void csv_writer::write_row(const std::vector<double>& data) {
	for (size_t i = 0; i < data.size(); ++i) {
		if (i > 0) file << ",";
		file << data[i];
	}
	file << "\n";
}

void csv_writer::write_header(const std::vector<std::string>& headers) {
	for (size_t i = 0; i < headers.size(); ++i) {
		if (i > 0) file << ",";
		file << headers[i];
	}
	file << "\n";
}

void csv_writer::close() {
	if (file.is_open()) {
		file.close();
	}
}
