#include "stdafx.h"
#include "Database.h"
#include <sstream>
#include <fstream>
#include <list>
#include <vector>
#include <codecvt>
#include <string_view>
#include <format>
#include <iostream>

void Database::load()
{
	std::wstring fname = L"Data/biblio.db";
	std::list<std::wstring> buffer;
	std::wstring line;

	const int amount_fields = 6;


	// open file
	std::wifstream ifs(fname.c_str());

	// check status of file
	if (!ifs)
	{
		throw std::exception("Error opening input file");
	}

	// reading raw data
	while (!ifs.eof())
	{
		std::getline(ifs, line,L'\n');
		buffer.push_back(line);
	}

	m_records.clear();
		

	int count = 0;
	// parsing data
	for (std::list<std::wstring>::iterator itr = buffer.begin(); itr != buffer.end(); itr++)
	{
		BiblioRecord rec;
		std::wstringstream  ss(*itr);
		std::vector<std::wstring> res;

		// split string into token
		while (ss.good())
		{
			std::wstring substr;
			std::getline(ss, substr, L';');
			res.push_back(substr);
		}
		
		// if itr is first string then check field's names
		if (itr == buffer.begin())
		{
			if (res[0] == L"id" && res[1] == L"UDK" && res[2] == L"FIO" && res[3] == L"name" && res[4] == L"year" && res[5] == L"ISBN")
				continue;
			else
				throw std::exception("Non correct file format");
		}

		if (res.size() < amount_fields)
			throw std::exception( (std::string("Non correct record:{}") + std::to_string(count)).c_str() );

		rec.fields = res;

		// filling out the record
		/*rec.id = std::stoi(res[0]);
		rec.udk = res[1];
		rec.fio = res[2];
		rec.bookName = res[3];
		rec.year = res[4];
		rec.isbn = res[5];*/

		//m_records.insert({ rec.id, rec });
		m_records.push_back(rec);
		count++;

	}


}



void Database::save()
{

}