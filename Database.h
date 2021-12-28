#pragma once
#include <string>
#include <map>
#include <memory> // for std::unique_ptr and std::make_unique
#include <vector>
#include <codecvt>

class Database
{
	// you can't call this constructor from outside
	Database() noexcept {}
	Database(const Database&) noexcept {}
	Database& operator=(const Database&) noexcept {}

	int getMaxID() const
	{
		int res = 0;
		for (auto rec : m_records)
		{
			const auto v = std::stoi(rec.fields[0]);
			res = (v > res) ? v : res;
		}
		return res;
	}

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
	void updateData(int row, int col, const std::wstring& s) 
	{
		m_records.at(row).fields.at(col) = s;
	}

	int insertRow(int row);
	void deleteRow(int row);

	void load(const std::wstring& fname);
	void save(const std::wstring& fname);


private:
	RecordMap m_records;

};

