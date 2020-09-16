#pragma once
#include<string>
#include<vector>

namespace AUX
{
	
	class CSV
	{
	public:
		CSV();
		CSV(std::string &fileName);
		~CSV();
		bool parse();
		void showData();
		void showLines();
		unsigned int getNumberOfRows();
	private:
		void setRow(std::string line);
		bool m_fileFlag;
		unsigned int m_rows;
		unsigned int m_columns;
		std::string m_fileName;
		std::vector<std::string> m_lines;
		std::vector<std::vector<std::string>> m_data;
	};
}