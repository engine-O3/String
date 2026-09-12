#ifndef STRING_H
#define STRING_H

#include <cstddef>

class String {

private:
	char* data_;
	size_t size_;
	size_t capacity_;

	static constexpr size_t npos = static_cast<size_t>(-1);

	static void copy_data_into_buffer(const char* data, const size_t data_size,
		char* buffer);
	static size_t calculate_size(const char* data);
	static size_t calculate_capacity(const size_t required_size,
		const size_t current_capacity = 0);
	static char* allocate_buffer(const size_t capacity);
	static size_t max_size();
	static bool is_data_alias(const char* left, const char* right);

	static String concatenate(const char* left, const String& right);
	static String concatenate(const char left, const String& right);

	static void concatenate_to_buffer(const char* left, const String& right,
		const size_t left_size, char* buffer);
	static void concatenate_to_buffer(const char left, const String& right,
		char* buffer);
	
	static bool compare_equal(const String& left, const String& right);
	static bool compare_equal(const char* left, const String& right);

	static int compare(const String& left, const String& right);
	static int compare(const String& left, const char* right);

	String concatenate(const String& other) const;
	String concatenate(const char* data) const;
	String concatenate(const char character) const;

	void concatenate_to_buffer(const String& other, char* buffer) const;
	void concatenate_to_buffer(const char* data, const size_t data_size,
		char* buffer) const;
	void concatenate_to_buffer(const char character, char* buffer) const;
	
	void append_data(const String& other, const size_t required_size);
	void append_data(const char* data, const size_t required_size);
	void append_data(const char character);

	void overwrite_data(const char* data, const size_t data_size);
	void overwrite_data(const char character);
	void replace_buffer(char* buffer, const size_t capacity);

	void move_suffix_to_buffer(char* buffer, const size_t suffix_count,
		const size_t required_size) const;
	void move_suffix(const size_t suffix_count, const size_t required_size) const;
	void copy_inserted_data(char* destination, const char* data, 
		const size_t data_size, const size_t index) const;
	void copy_prefix_to_buffer(char* buffer, const size_t index) const;

	String(char* data, const size_t size, const size_t capacity);

public:
	String();
	String(const char* data);
	String(const String& other);
	String(String&& other) noexcept;
	~String();

	const char* data() const;
	size_t size() const;
	size_t length() const;
	size_t capacity() const;

	bool is_empty() const;
	void clear();

	const char* c_str() const;

	char& at(const size_t index);
	const char& at(const size_t index) const;

	char& front();
	const char& front() const;
	char& back();
	const char& back() const;

	String& assign(const String& other);
	String& assign(const char* data);
	String& assign(const char character);

	String& append(const String& other);
	String& append(const char* data);
	String& append(const char character);

	void insert(const size_t index, const char* data);
	void insert(const size_t index, const char character);
	void erase(const size_t index, const size_t count);

	int compare(const String& other) const;
	int compare(const char* data) const;

	bool compare_equal(const String& other) const;
	bool compare_equal(const char* data) const;

	size_t find(const char* substring) const;
	String substr(const size_t begin, const size_t end) const;

	char* begin();
	const char* begin() const;
	char* end();
	const char* end() const;

	void reserve(const size_t capacity);
	void shrink_to_fit();

	String& operator=(const String& other);
	String& operator=(const char* data);
	String& operator=(String&& other) noexcept;

	String operator+(const String& other) const;
	String operator+(const char* data) const;
	String operator+(const char character) const;
	
	String& operator+=(const String& other);
	String& operator+=(const char* data);
	String& operator+=(const char character);

	char& operator[](const size_t index);
	const char& operator[](const size_t index) const;

	bool operator==(const String& other) const;
	bool operator==(const char* data) const;
	bool operator!=(const String& other) const;
	bool operator!=(const char* data) const;

	bool operator<(const String& other) const;
	bool operator<(const char* data) const;
	bool operator>(const String& other) const;
	bool operator>(const char* data) const;

	bool operator<=(const String& other) const;
	bool operator<=(const char* data) const;
	bool operator>=(const String& other) const;
	bool operator>=(const char* data) const;

	friend String operator+(const char* left, const String& right);
	friend String operator+(const char left, const String& right);

	friend bool operator==(const char* left, const String& right);
	friend bool operator!=(const char* left, const String& right);

	friend bool operator<(const char* left, const String& right);
	friend bool operator>(const char* left, const String& right);
	friend bool operator<=(const char* left, const String& right);
	friend bool operator>=(const char* left, const String& right);
};

#endif
