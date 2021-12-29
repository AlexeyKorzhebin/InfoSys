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

void Database::load(const std::wstring& fname)
{
	
	std::list<std::wstring> buffer;
	std::wstring line;


	// open file
	std::wifstream ifs(fname.c_str());

	// check status of file
	if (!ifs)
	{
		throw std::exception("Файл не существует или указан неправильный путь");
	}

	// reading raw data
	while (!ifs.eof())
	{
		std::getline(ifs, line,L'\n');
		buffer.push_back(line);
	}

	// clear current records
	m_records.clear();
		

	int count = 0;
	// parsing data
	for (std::list<std::wstring>::const_iterator itr = buffer.begin(); itr != buffer.end(); itr++)
	{
		BiblioRecord rec;
		std::wstringstream  ss(*itr);
		std::vector<std::wstring> res;

		// split string into token
		while (ss.good() && res.size() < amountFields)
		{
			std::wstring substr;
			std::getline(ss, substr, L';');
			res.push_back(substr);
		}
		
		// if itr is first string then check field's names
		if (itr == buffer.begin())
		{
			if (res.at(0) == L"ID" && res.at(1) == L"УДК" && res.at(2) == L"Автор" && res.at(3) == L"Название" && res.at(4) == L"Год" && res.at(5) == L"ISBN")
				continue;
			else
				throw std::exception("Некорректный формат файла");
		}

		if (res.size() < amountFields)
			throw std::exception( (std::string("Некорректная запись:") + std::to_string(count)).c_str() );

		rec.fields = res;

		// filling out the record
		m_records.push_back(rec);
		count++;

	}


}



void Database::save(const std::wstring& fname)
{
	std::wofstream ofs(fname.c_str());

	// save the header
	for (const auto fieldName : fieldNames)
		ofs << fieldName << L";";


	// save data
	for (const auto record : m_records)
	{
		ofs << std::endl;
		for (const auto field : record.fields)
		{
			ofs << field.c_str() << L";";
			//b_save = true;
		}
		
		// if one field is exist then insert return caret
		//if (b_save)
		//{
		//	ofs << std::endl;
		//}
	}


}

int Database::insertRow(int row)
{
	// fin max_id
	const auto id = getMaxID() + 1;
	BiblioRecord rec;
	rec.fields.resize(amountFields);
	// fill out the field "id"
	rec.fields[0] = std::to_wstring(id);

	//if(m_records.empty())
	if(row == -1)
		m_records.push_back(rec);
	else
		m_records.insert(m_records.begin() + row - 1, rec);
	
	return id;
}

void Database::deleteRow(int row)
{
	m_records.erase(m_records.begin() + row);
}