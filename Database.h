#pragma once
#include <string>
#include <map>
#include <memory> // for std::unique_ptr and std::make_unique



class Database
{
	// you can't call this constructor from outside
	Database() noexcept {}
	Database(const Database&) noexcept {}
	Database& operator=(const Database&) noexcept {}

public:

	struct BiblioRecord
	{
		int id; // key
		std::wstring udk;
		std::wstring fio;
		std::wstring bookName;
		std::wstring year;
		std::wstring isbn;
	};

	typedef std::map<int, Database::BiblioRecord> RecordMap;
	static Database& getInstance() noexcept
	{
		static Database m_db;
		return m_db;
	}

	const RecordMap& getRecords() const { return m_records; }

	void load();
	void save();

	const wchar_t* m_fields[6] = { L"ID", L"УДК", L"Автор", L"Название", L"Год", L"ISBN" };

private:
	RecordMap m_records;

};

