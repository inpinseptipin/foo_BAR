#include <csv.h>
#include <iostream>
#include <fstream>
#include <sstream>

namespace AUX
{
/*******************************Constructors********************************/

	// Default Constructor : Initializes Constructor with m_fileFlag=false;
	CSV::CSV()
	{
		m_fileFlag = false;
	}

	// Argument Constructor : Initializes Constructor with fileName
	CSV::CSV(std::string &fileName)
	{
		m_fileName = fileName;
		m_fileFlag = true;
	}

	// Destructor 
	CSV::~CSV()
	{
		if (m_fileFlag)
			std::cout << "Terminating Connection to " << m_fileName << std::endl;
		else if (!m_fileFlag)
			std::cout << "No File Loaded" << std::endl;
	}

/*******************************Private Methods********************************/

	// Method : Inserts Row in the Table
	void CSV::setRow(std::string line)
	{
		std::vector<std::string> row;
		int j = 0;
		for (int i = 0; i < line.length(); i++)
		{
			if (line[i] == ',')
			{
				row.push_back(line.substr(j, i-j));
				j = i+1;
			}
		}
		m_data.push_back(row);
		m_rows++;
	}

	// Method : Arranges the Raw Lines into a Table
	

/*******************************Public Methods********************************/

	// Method : Parses the CSV file and loads it into a String Vector
	bool CSV::parse()
	{
		if (!m_fileFlag)
			return false;
		std::ifstream file;
		file.open(m_fileName, std::ifstream::in);
		if (file.is_open())
		{
			std::stringstream stringStream;
			std::string line;
			std::string cell;
			int count = 0;
			while (std::getline(file, line))
			{
				stringStream << line;
				while (std::getline(stringStream, cell, ','))
				{
					for (int i = 0; i < cell.length(); i++)
					{
						if (cell[i] == '\n')
							count++;
					}
				}
				//m_lines.push_back(line);
			}
			std::cout << count;
			return true;
		}
		else
		{
			std::cout << "File Does not exist" << std::endl;
			return false;
		}
	}

	// Method : Displays the Table Data 
	void CSV::showData()
	{
		for (auto i = m_data.begin(); i != m_data.end(); ++i)
		{
			for (auto j = i->begin(); j != i->end(); ++j)
			{
				std::cout << *j << " | ";
			}
			std::cout << '\n';
		}
	}

	// Method : Displays the Raw CSV Data
	void CSV::showLines()
	{
		for (auto i = m_lines.begin(); i != m_lines.end(); ++i)
		{
			std::cout << *i << std::endl;
		}
	}

	// Method : Returns Number of Rows in the CSV File
	unsigned int CSV::getNumberOfRows()
	{
		return m_rows;
	}
}