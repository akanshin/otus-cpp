#ifndef OTUS_CPP_IP_FILTER_IP_H
#define OTUS_CPP_IP_FILTER_IP_H

#include "ipf_exports.h"

#include <array>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <initializer_list>


namespace ipf
{

class IPF_API IPv4
{
public:
    IPv4(); //127.0.0.1
    IPv4(const char *);         // "x.x.x.x" or "localhost"
    IPv4(const wchar_t *);      // L"x.x.x.x" or L"localhost"
	IPv4(const std::string &);  // "x.x.x.x" or "localhost"
	IPv4(const std::wstring &); // L"x.x.x.x" or L"localhost"
	IPv4(std::byte, std::byte, std::byte, std::byte);
	IPv4(int, int, int, int);

	IPv4(const IPv4 &) = default;
	IPv4(IPv4 &&) = default;
	IPv4 & operator=(const IPv4 &) = default;
	IPv4 & operator=(IPv4 &&) = default;

	std::string toString() const;
	std::wstring toWString() const;

	std::byte operator[](std::size_t) const;
	std::byte & operator[](std::size_t);

	bool operator<(const IPv4 & other) const;
	bool operator==(const IPv4 & other) const;

	auto begin() const noexcept { return m_aData.begin(); }
	auto end() const noexcept { return m_aData.end(); }
	auto cbegin() const noexcept { return m_aData.cbegin(); }
	auto cend() const noexcept { return m_aData.cend(); }

private:
	std::array<std::byte, 4> m_aData;
};

} // namespace ipf

namespace std
{

inline auto begin(ipf::IPv4 & ip) noexcept { return ip.begin(); }
inline auto end(ipf::IPv4 & ip) noexcept { return ip.end(); }
inline auto cbegin(ipf::IPv4 & ip) noexcept { return ip.cbegin(); }
inline auto cend(ipf::IPv4 & ip) noexcept { return ip.cend(); }

template<>
struct IPF_API hash<ipf::IPv4>
{
	std::size_t operator()(ipf::IPv4 const & ip) const noexcept
	{
		std::uint32_t d = 0;
		for (const auto & b : ip)
		{
			d <<= 8;
			d |= std::to_integer<int>(b);
		}
		return std::hash<std::uint32_t>()(d);
	}
};

} //namespace std

#endif //OTUS_CPP_IP_FILTER_IP_H
