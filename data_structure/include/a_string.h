#pragma once
#include <ostream>
#include <istream>
using std::ostream;
using std::istream;

class a_string {
public:
	a_string();
	a_string(const char* cstr);
	a_string(size_t len, char c);
	a_string(const a_string& r);
	a_string(a_string&& r) noexcept;
	~a_string();

	a_string& operator=(const char* cstr);
	a_string& operator=(const a_string& r);
	a_string& operator=(a_string&& r) noexcept;

	char& operator[](size_t i);
	const char& operator[](size_t i) const;	// this指针是const a_string*类型的
	a_string& operator+=(a_string& s);
	a_string& operator+=(const char* cstr);

	friend ostream& operator<<(ostream& out, const a_string& s);

	bool operator==(const a_string& r);
	bool operator!=(const a_string& r);

	char* get_cstr() const;
	size_t size() const;
	void swap(a_string& s);
private:
	char* cstr_ = nullptr;
};

