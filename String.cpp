#include "String.h"
#include <stdexcept>

String::String() {

	data_ = new char[1];
	data_[0] = '\0';
	size_ = 0;
	capacity_ = 0;
}

String::String(const char* data) {

	const size_t size = calculate_size(data);
	const size_t capacity = calculate_capacity(size);

	char* buffer = allocate_buffer(capacity);
	copy_data_into_buffer(data, size, buffer);

	data_ = buffer;
	size_ = size;
	capacity_ = capacity;
}

String::String(const String& other) {

	char* buffer = allocate_buffer(other.capacity_);
	copy_data_into_buffer(other.data_, other.size_, buffer);

	data_ = buffer;
	size_ = other.size_;
	capacity_ = other.capacity_;
}

String::String(String&& other) noexcept {

	data_ = other.data_;
	size_ = other.size_;
	capacity_ = other.capacity_;

	other.data_ = nullptr;
	other.size_ = 0;
	other.capacity_ = 0;
}

// Private Constructor - Transfer Ownership
String::String(char* data, const size_t size, const size_t capacity) {
	data_ = data;
	size_ = size;
	capacity_ = capacity;
}

String::~String() {
	delete[] data_;
}

void String::copy_data_into_buffer(const char* data, const size_t data_size,
	char* buffer) {

	for (size_t i = 0; i <= data_size; ++i) {
		buffer[i] = data[i];
	}
}

size_t String::calculate_size(const char* data) {

	const char* copy_ptr = data;
	size_t size = 0;

	while (*copy_ptr) {
		++size;
		++copy_ptr;
	}

	return size;
}

size_t String::max_size() {
	return 1ULL << 24;
}

char* String::allocate_buffer(const size_t capacity) {

	if (capacity > max_size()) {
		throw std::length_error("String size exceeds maximum size of 2^24");
	}

	return new char[capacity + 1];
}

size_t String::calculate_capacity(const size_t required_size,
	const size_t current_capacity) {

	if (required_size > max_size()) {
		throw std::length_error("String size exceeds maximum size of 2^24");
	}

	size_t capacity = required_size;

	if (capacity < (2 * current_capacity)) {
		capacity = (2 * current_capacity);
	}

	if (capacity > max_size()) {
		capacity = max_size();
	}

	return capacity;
}

String String::concatenate(const char* left, const String& right) {

	const size_t left_size = String::calculate_size(left);
	const size_t required_size = left_size + right.size_;
	char* buffer = String::allocate_buffer(required_size);

	String::concatenate_to_buffer(left, right, left_size, buffer);

	return String(buffer, required_size, required_size);
}

String String::concatenate(const char left, const String& right) {

	const size_t required_size = 1 + right.size_;
	char* buffer = String::allocate_buffer(required_size);

	String::concatenate_to_buffer(left, right, buffer);

	return String(buffer, required_size, required_size);
}

void String::concatenate_to_buffer(const char* left, const String& right,
	const size_t left_size, char* buffer) {

	for (size_t i = 0; i < left_size; ++i) {
		buffer[i] = left[i];
	}

	for (size_t i = 0; i <= right.size_; ++i) {
		buffer[left_size + i] = right.data_[i];
	}
}

void String::concatenate_to_buffer(const char left, const String& right, char* buffer) {

	buffer[0] = left;

	for (size_t i = 0; i <= right.size_; ++i) {
		buffer[1 + i] = right.data_[i];
	}
}

bool String::compare_equal(const String& left, const String& right) {

	if (left.size_ != right.size_) {
		return false;
	}

	for (size_t i = 0; i < left.size_; ++i) {

		if (left.data_[i] != right.data_[i]) {
			return false;
		}
	}

	return true;
}

bool String::compare_equal(const char* left, const String& right) {

	const size_t left_size = calculate_size(left);

	if (left_size != right.size_) {
		return false;
	}

	for (size_t i = 0; i < left_size; ++i) {

		if (left[i] != right.data_[i]) {
			return false;
		}
	}

	return true;
}

int String::compare(const String& left, const String& right) {

	size_t size = right.size_;

	if (left.size_ < right.size_) {
		size = left.size_;
	}

	for (size_t i = 0; i < size; ++i) {

		if (left.data_[i] < right.data_[i]) {
			return -1; // left is lexicographically smaller
		}
		else if (left.data_[i] > right.data_[i]) {
			return 1; // left is lexicographically greater
		}
	}

	if (left.size_ < right.size_) {
		return -1; // left is shorter
	}
	else if (left.size_ > right.size_) {
		return 1; // left is longer
	}

	return 0; // strings are equal
}

int String::compare(const String& left, const char* right) {

	size_t right_size = calculate_size(right);
	size_t size = right_size;

	if (left.size_ < right_size) {
		size = left.size_;
	}

	for (size_t i = 0; i < size; ++i) {

		if (left.data_[i] < right[i]) {
			return -1; // left is lexicographically smaller
		}
		else if (left.data_[i] > right[i]) {
			return 1; // left is lexicographically greater
		}
	}

	if (left.size_ < right_size) {
		return -1; // left is shorter
	}
	else if (left.size_ > right_size) {
		return 1; // left is longer
	}

	return 0; // strings are equal
}

String String::concatenate(const String& other) const {

	const size_t required_size = size_ + other.size_;
	char* buffer = allocate_buffer(required_size);

	concatenate_to_buffer(other, buffer);

	return String(buffer, required_size, required_size);
}

String String::concatenate(const char* data) const {

	const size_t data_size = calculate_size(data);
	const size_t required_size = size_ + data_size;
	char* buffer = allocate_buffer(required_size);

	concatenate_to_buffer(data, data_size, buffer);

	return String(buffer, required_size, required_size);
}

String String::concatenate(const char character) const {

	const size_t required_size = size_ + 1;
	char* buffer = allocate_buffer(required_size);

	concatenate_to_buffer(character, buffer);

	return String(buffer, required_size, required_size);
}

void String::concatenate_to_buffer(const String& other, char* buffer) const {

	for (size_t i = 0; i < size_; ++i) {
		buffer[i] = data_[i];
	}

	for (size_t i = 0; i <= other.size_; ++i) {
		buffer[size_ + i] = other.data_[i];
	}
}

void String::concatenate_to_buffer(const char* data, const size_t data_size,
	char* buffer) const {

	for (size_t i = 0; i < size_; ++i) {
		buffer[i] = data_[i];
	}

	for (size_t i = 0; i <= data_size; ++i) {
		buffer[size_ + i] = data[i];
	}
}

void String::concatenate_to_buffer(const char character, char* buffer) const {

	for (size_t i = 0; i < size_; ++i) {
		buffer[i] = data_[i];
	}

	buffer[size_] = character;
	buffer[size_ + 1] = '\0';
}

void String::append_data(const String& other, const size_t required_size) {

	for (size_t i = size_; i <= required_size; ++i) {
		data_[i] = other.data_[i - size_];
	}
}

void String::append_data(const char* data, const size_t required_size) {

	for (size_t i = size_; i <= required_size; ++i) {
		data_[i] = data_[i - size_];
	}
}

void String::append_data(const char character) {

	data_[size_] = character;
	data_[size_ + 1] = '\0';
}

void String::overwrite_data(const char* data, const size_t data_size) {

	for (size_t i = 0; i <= data_size; ++i) {
		data_[i] = data[i];
	}

	for (size_t i = data_size + 1; i <= size_; ++i) {
		data_[i] = '\0';
	}
}

void String::overwrite_data(const char character) {

	data_[0] = character;
	data_[1] = '\0';

	for (size_t i = 2; i <= size_; ++i) {
		data_[i] = '\0';
	}
}

void String::replace_buffer(char* buffer, const size_t capacity) {
	delete[] data_;
	data_ = buffer;
	capacity_ = capacity;
}

void String::move_suffix_to_buffer(char* buffer, const size_t suffix_count,
	const size_t required_size) const {

	for (size_t i = 0; i <= suffix_count; ++i) {
		buffer[required_size - i] = data_[size_ - i];
	}
}

void String::move_suffix(const size_t suffix_count,
	const size_t required_size) const {

	for (size_t i = 0; i <= suffix_count; ++i) {
		data_[required_size - i] = data_[size_ - i];
	}
}

void String::copy_inserted_data(char* destination, const char* data,
	const size_t data_size, const size_t index) const {

	for (size_t i = 0; i < data_size; ++i) {
		destination[index + i] = data[i];
	}
}

void String::copy_prefix_to_buffer(char* buffer, const size_t index) const {

	for (size_t i = 0; i < index; ++i) {
		buffer[i] = data_[i];
	}
}

int String::compare(const String& other) const {
	return compare(*this, other);
}

int String::compare(const char* data) const {
	return compare(*this, data);
}

bool String::compare_equal(const String& other) const {
	return compare_equal(*this, other);
}

bool String::compare_equal(const char* data) const {
	return compare_equal(data, *this);
}

const char* String::data() const {
	return data_;
}

size_t String::size() const {
	return size_;
}

size_t String::length() const {
	return size_;
}

size_t String::capacity() const {
	return capacity_;
}

const char* String::c_str() const {
	return data_;
}

bool String::is_empty() const {
	return data_[0] == '\0';
}

void String::clear() {

	for (size_t i = 0; i < size_; ++i) {
		data_[i] = '\0';
	}

	size_ = 0;
}

char& String::at(const size_t index) {

	if (index >= size_) {
		throw std::out_of_range("Index is out of range");
	}

	return data_[index];
}

const char& String::at(const size_t index) const {

	if (index >= size_) {
		throw std::out_of_range("Index is out of range");
	}

	return data_[index];
}

void String::reserve(const size_t capacity) {

	if (capacity_ >= capacity) {
		return;
	}

	char* buffer = allocate_buffer(capacity);
	copy_data_into_buffer(data_, size_, buffer);

	delete[] data_;
	data_ = buffer;
	capacity_ = capacity;
}

void String::shrink_to_fit() {

	char* buffer = allocate_buffer(size_);
	copy_data_into_buffer(data_, size_, buffer);
	replace_buffer(buffer, size_);
}

char& String::front() {
	return data_[0];
}

const char& String::front() const {
	return data_[0];
}

char& String::back() {
	return data_[size_ - 1];
}

const char& String::back() const {
	return data_[size_ - 1];
}

String& String::assign(const String& other) {

	if (this == &other) {
		return *this;
	}

	if (capacity_ < other.size_) {

		char* buffer = allocate_buffer(other.capacity_);

		copy_data_into_buffer(other.data_, other.size_, buffer);
		replace_buffer(buffer, other.capacity_);
	}
	else {
		overwrite_data(other.data_, other.size_);
	}

	size_ = other.size_;
	return *this;
}

String& String::assign(const char* data) {

	const size_t data_size = calculate_size(data);

	if (capacity_ < data_size) {

		const size_t new_capacity = calculate_capacity(data_size, capacity_);
		char* buffer = allocate_buffer(new_capacity);

		copy_data_into_buffer(data, data_size, buffer);
		replace_buffer(buffer, new_capacity);
	}
	else {
		overwrite_data(data, data_size);
	}

	size_ = data_size;
	return *this;
}

String& String::assign(const char character) {

	const size_t required_size = 1;

	if (capacity_ < required_size) {

		const size_t new_capacity = calculate_capacity(required_size, capacity_);
		char* buffer = allocate_buffer(new_capacity);

		buffer[0] = character;
		buffer[1] = '\0';

		replace_buffer(buffer, new_capacity);
	}
	else {
		overwrite_data(character);
	}

	size_ = required_size;
	return *this;
}

String& String::append(const String& other) {

	const size_t required_size = size_ + other.size_;

	if (capacity_ < required_size) {

		const size_t new_capacity = calculate_capacity(required_size, capacity_);
		char* buffer = allocate_buffer(new_capacity);

		concatenate_to_buffer(other, buffer);
		replace_buffer(buffer, new_capacity);
	}
	else {
		append_data(other, required_size);
	}

	size_ = required_size;
	return *this;
}

String& String::append(const char* data) {

	const size_t data_size = calculate_size(data);
	const size_t required_size = size_ + data_size;

	if (capacity_ < required_size) {

		const size_t new_capacity = calculate_capacity(required_size, capacity_);
		char* buffer = allocate_buffer(new_capacity);

		concatenate_to_buffer(data, data_size, buffer);
		replace_buffer(buffer, new_capacity);
	}
	else {
		append_data(data, required_size);
	}

	size_ = required_size;
	return *this;
}

String& String::append(const char character) {

	const size_t required_size = size_ + 1;

	if (capacity_ < required_size) {

		const size_t new_capacity = calculate_capacity(required_size, capacity_);
		char* buffer = allocate_buffer(new_capacity);

		concatenate_to_buffer(character, buffer);
		replace_buffer(buffer, new_capacity);
	}
	else {
		append_data(character);
	}

	size_ = required_size;
	return *this;
}

bool String::is_data_alias(const char* left, const char* right) {

	for (size_t i = 0; left[i] != '\0'; ++i) {

		for (size_t j = 0; right[j] != '\0'; ++j) {

			if (&left[i] == &right[j]) {
				return true;
			}
		}
	}

	return false;
}

void String::insert(const size_t index, const char* data) {

	if (index > size_) {
		throw std::out_of_range("Index is out of range");
	}

	const size_t data_size = calculate_size(data);
	const size_t required_size = size_ + data_size;
	const size_t suffix_count = size_ - index;

	if (capacity_ < required_size) {

		const size_t new_capacity = calculate_capacity(required_size, capacity_);
		char* buffer = allocate_buffer(new_capacity);

		move_suffix_to_buffer(buffer, suffix_count, required_size);
		copy_inserted_data(buffer, data, data_size, index);
		copy_prefix_to_buffer(buffer, index);

		replace_buffer(buffer, new_capacity);
	}
	else if (!is_data_alias(data_, data)) {
		move_suffix(suffix_count, required_size);
		copy_inserted_data(data_, data, data_size, index);
	}
	else {
		char* buffer = allocate_buffer(data_size);
		copy_data_into_buffer(data, data_size, buffer);

		move_suffix(suffix_count, required_size);
		copy_inserted_data(data_, buffer, data_size, index);

		delete[] buffer;
	}

	size_ = required_size;
}

void String::insert(const size_t index, const char character) {

	if (index > size_) {
		throw std::out_of_range("Index is out of range");
	}

	const size_t required_size = size_ + 1;
	const size_t suffix_count = size_ - index;

	if (capacity_ < required_size) {

		const size_t new_capacity = calculate_capacity(required_size,
			capacity_);
		char* buffer = allocate_buffer(new_capacity);

		move_suffix_to_buffer(buffer, suffix_count, required_size);
		buffer[index] = character;
		copy_prefix_to_buffer(buffer, index);

		replace_buffer(buffer, new_capacity);
	}
	else {
		move_suffix(suffix_count, required_size);
		data_[index] = character;
	}

	size_ = required_size;
}

void String::erase(const size_t index, const size_t count) {

	if (index >= size_) {
		throw std::out_of_range("Index is out of range");
	}

	const size_t remaining_count_size = size_ - index;

	if (count > remaining_count_size) {
		throw std::out_of_range("Count is bigger than remaining count size");
	}

	const size_t erase_end = index + count;
	const size_t right_remaining_size = size_ - erase_end;

	for (size_t i = 0; i <= right_remaining_size; ++i) {
		data_[index + i] = data_[erase_end + i];
	}

	for (size_t i = 0; i <= right_remaining_size; ++i) {
		data_[erase_end + i] = '\0';
	}

	size_ -= count;
}

size_t String::find(const char* substring) const {

	const size_t substring_size = calculate_size(substring);

	if (substring_size > size_) {
		return npos;
	}

	size_t j = 0;

	for (size_t i = 0; i < size_; ++i) {

		if (size_ - i < substring_size) {
			return npos;
		}

		while (j < substring_size && size_ > i + j &&
			data_[i + j] == substring[j]) {
			j++;
		}

		if (substring_size == j) {
			return i;
		}

		j = 0;
	}
	return npos;
}

String String::substr(const size_t begin, const size_t end) const {

	if (begin >= size_ || end >= size_ || begin > end) {
		throw std::out_of_range("Begin/End Index is out of range");
	}

	const size_t size = end - begin + 1;
	char* buffer = allocate_buffer(size);

	for (size_t i = 0; i < size; ++i) {
		buffer[i] = data_[begin + i];
	}

	buffer[size] = '\0';

	return String(buffer, size, size);
}

char* String::begin() {
	return data_;
}

const char* String::begin() const {
	return data_;
}

char* String::end() {
	return data_ + size_;
}

const char* String::end() const {
	return data_ + size_;
}

String& String::operator=(const String& other) {
	return assign(other);
}

String& String::operator=(const char* data) {
	return assign(data);
}

String& String::operator=(String&& other) noexcept {

	if (this != &other) {

		delete[] data_;

		data_ = other.data_;
		size_ = other.size_;
		capacity_ = other.capacity_;

		other.data_ = nullptr;
		other.size_ = 0;
		other.capacity_ = 0;
	}

	return *this;
}

String String::operator+(const String& other) const {
	return concatenate(other);
}

String String::operator+(const char* data) const {
	return concatenate(data);
}

String String::operator+(const char character) const {
	return concatenate(character);
}

String operator+(const char* left, const String& right) {
	return String::concatenate(left, right);
}

String operator+(const char left, const String& right) {
	return String::concatenate(left, right);
}

String& String::operator+=(const String& other) {
	return append(other);
}

String& String::operator+=(const char* data) {
	return append(data);
}

String& String::operator+=(const char character) {
	return append(character);
}

char& String::operator[](const size_t index) {
	return data_[index];
}

const char& String::operator[](const size_t index) const {
	return data_[index];
}

bool String::operator==(const String& other) const {
	return compare_equal(*this, other);
}

bool String::operator==(const char* data) const {
	return compare_equal(data, *this);
}

bool String::operator!=(const String& other) const {
	return !compare_equal(*this, other);
}

bool String::operator!=(const char* data) const {
	return !compare_equal(data, *this);
}

bool String::operator<(const String& other) const {
	return compare(*this, other) < 0;
}

bool String::operator<(const char* data) const {
	return compare(*this, data) < 0;
}

bool String::operator>(const String& other) const {
	return compare(*this, other) > 0;
}

bool String::operator>(const char* data) const {
	return compare(*this, data) > 0;
}

bool String::operator<=(const String& other) const {
	return compare(*this, other) <= 0;
}

bool String::operator<=(const char* data) const {
	return compare(*this, data) <= 0;
}

bool String::operator>=(const String& other) const {
	return compare(*this, other) >= 0;
}

bool String::operator>=(const char* data) const {
	return compare(*this, data) >= 0;
}

bool operator==(const char* left, const String& right) {
	return String::compare_equal(left, right);
}

bool operator!=(const char* left, const String& right) {
	return !String::compare_equal(left, right);
}

bool operator<(const char* left, const String& right) {
	return String::compare(right, left) > 0;
}

bool operator>(const char* left, const String& right) {
	return String::compare(right, left) < 0;
}

bool operator<=(const char* left, const String& right) {
	return String::compare(right, left) >= 0;
}

bool operator>=(const char* left, const String& right) {
	return String::compare(right, left) <= 0;
}
