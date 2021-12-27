#pragma once
#include <string>
#include <map>
#include <memory> // for std::unique_ptr and std::make_unique
#include <vector>



class Database
{
	// you can't call this constructor from outside
	Database() noexcept {}
	Database(const Database&) noexcept {}
	Database& operator=(const Database&) noexcept {}

public:

	const wchar_t* fieldNames[6] = { L"ID", L"УДК", L"Автор", L"Название", L"Год", L"ISBN" };
	const int amountFields = 6;

	
	struct BiblioRecord
	{
		std::vector<std::wstring> fields;
		int id; // key
		std::wstring udk;
		std::wstring fio;
		std::wstring bookName;
		std::wstring year;
		std::wstring isbn;
	};

	typedef std::vector<Database::BiblioRecord> RecordMap;
	static Database& getInstance() noexcept
	{
		static Database m_db;
		return m_db;
	}

	const RecordMap& getRecords() const { return m_records; }

	void load(const std::wstring& fname);
	void save(const std::wstring& fname);


private:
	RecordMap m_records;

};

