#ifndef OTUS_CPP_IP_FILTER_IP_H
#define OTUS_CPP_IP_FILTER_IP_H

#include "ipf_exports.h"

#include <array>
#include <cstdint>
#include <functional>
#include <initializer_list>

namespace ipf
{

class IPF_API IPv4
{
public:
	IPv4(); //127.0.0.1
	IPv4(const std::string &);  // "x.x.x.x" or "localhost"
	IPv4(const char *);         // "x.x.x.x" or "localhost"
	IPv4(const std::wstring &); // L"x.x.x.x" or L"localhost"
	IPv4(const wchar_t *);      // L"x.x.x.x" or L"localhost"
	IPv4(std::uint8_t, std::uint8_t, std::uint8_t, std::uint8_t);
	typename<typename T>
	IPv4(std::initializer_list<T> l)
	{
		static_assert(std::is_integral_v<T> && !std::is_same_v<T, bool>, "Only integral types (except bool) are supported!");
		static_assert(l.size() == 4, "IPv4 have 4 bytes!");
		std::array<T, 4> a = l;
		init(static_cast<std::uint8_t>(a[0]), static_cast<std::uint8_t>(a[1]),
			 static_cast<std::uint8_t>(a[2]), static_cast<std::uint8_t>(a[3]));
	}

	std::string toString() const;
	std::wstring toWString() const;

	std::uint8_t operator[](std::size_t) const;
	std::uint8_t & operator[](std::size_t);

	bool operator<(const IPv4 & other) const;
	bool operator==(const IPv4 & other) const;

private:
	std::array<std::uint8_t, 4> m_aData;
}

} // namespace ipf

namespace std
{

template<>
struct IPF_API hash<ipf::IPv4>
{
	std::size_t operator()(IPv4 const &) const noexcept;
};

} //namespace std

#endif //OTUS_CPP_IP_FILTER_IP_H
