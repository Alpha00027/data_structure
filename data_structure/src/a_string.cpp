#include "a_string.h"
#include "a_cstring.h"

a_string::a_string() {
	cstr_ = new char[1];
	cstr_[0] = '\0';
}

a_string::a_string(const char* cstr) {
	size_t len = a_strlen(cstr);

	cstr_ = new char[len + 1];
	a_strcpy(cstr_, cstr);
}

a_string::a_string(size_t len, char c) {
	cstr_ = new char[len + 1];
	for (size_t l = 0; l < len; l++) {
		cstr_[l] = c;
	}
	cstr_[len] = '\0';
}

a_string::a_string(const a_string& r) {
	cstr_ = new char[r.size() + 1];
	a_strcpy(cstr_, r.get_cstr());
}

a_string::a_string(a_string&& r) noexcept {
	cstr_ = r.cstr_;
	r.cstr_ = nullptr;
}

a_string::~a_string() {
	if (cstr_ != nullptr) delete[] cstr_;
}

a_string& a_string::operator=(const char* cstr) {
	a_string s(cstr);
	swap(s);
	return *this;
}

a_string& a_string::operator=(const a_string& r) {
	a_string tmp(r);// 使用r来构造一份副本,copy and swap，异常安全，自我赋值
	swap(tmp);	// 交换当前值和副本值
	return *this;
}

a_string& a_string::operator=(a_string&& r) noexcept {
	if (cstr_ != nullptr) delete[] cstr_;
	cstr_ = r.cstr_;
	r.cstr_ = nullptr;
	return *this;
}

char& a_string::operator[](size_t i) {
	return cstr_[i];
}

const char& a_string::operator[](size_t i) const {
	return cstr_[i];
}

a_string& a_string::operator+=(a_string& s) {
	size_t len = this->size() + s.size();
	a_string tmp(len, '\0');

	a_strcpy(tmp.cstr_, this->cstr_);
	a_strcpy(&tmp.cstr_[this->size()], s.cstr_);

	swap(tmp);

	return *this;
}

a_string& a_string::operator+=(const char* cstr) {
	int len = this->size() + a_strlen(cstr);
	a_string tmp(len, '\0');

	a_strcpy(tmp.cstr_, this->cstr_);
	a_strcpy(&tmp.cstr_[this->size()], cstr);

	swap(tmp);

	return *this;
}

ostream& operator<<(ostream& out, const a_string& s) {
	for (size_t i = 0; i < s.size(); i++) {
		out << s[i] << " ";
	}
	return out;
}

bool a_string::operator==(const a_string& r) {
	int i = a_strcmp(this->cstr_, r.cstr_);
	if (i == 0)	return true;
	else return false;
}

bool a_string::operator!=(const a_string& r) {
	return !operator==(r);
}

char* a_string::get_cstr() const {
	return this->cstr_;
}

size_t a_string::size() const {
	return a_strlen(this->cstr_);
}

/**
 * @brief 交换s与当前对象的值
 * @param s 被交换对象
*/
void a_string::swap(a_string& s) {
	char* tmp = cstr_;
	cstr_ = s.cstr_;
	s.cstr_ = tmp;
}