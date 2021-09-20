#include "precompiled.h"
#include "ipf_ip.h"

namespace ipf
{

static const std::string s_slocalhost{ "localhost" };
static const std::wstring s_wslocalhost{ L"localhost" };
static const std::array<IPv4::byte, 4> s_localhost{ IPv4::byte(127), IPv4::byte(0), IPv4::byte(0), IPv4::byte(1) };

static const std::regex s_regex{ "^(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\."
                                 "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\."
                                 "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\."
                                 "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$" };

static const std::wregex s_wregex{ L"^(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\."
                                   L"(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\."
                                   L"(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\."
                                   L"(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$" };

IPv4::IPv4()
    : m_aData{ s_localhost }
{}

IPv4::IPv4(const char * pStr)
    : IPv4()
{
    if (pStr == s_slocalhost)
        return;

    if (!std::regex_match(pStr, s_regex))
        throw std::invalid_argument("IPv4: wrong format.");

    std::stringstream ss{ pStr };
    std::string uint8_tStr;
    std::size_t idx = 0;
    while (std::getline(ss, uint8_tStr, '.'))
    {
        int a = std::stoi(uint8_tStr);
        m_aData[idx++] = byte(a);
    }
}

IPv4::IPv4(const wchar_t * pStr)
    : IPv4()
{
    if (pStr == s_wslocalhost)
        return;

    if (!std::regex_match(pStr, s_wregex))
        throw std::invalid_argument("IPv4: wrong format.");

    std::wstringstream ss{ pStr };
    std::wstring uint8_tStr;
    std::size_t idx = 0;
    while (std::getline(ss, uint8_tStr, L'.'))
    {
        int a = std::stoi(uint8_tStr);
        m_aData[idx++] = byte(a);
    }
}

IPv4::IPv4(const std::string & str)
    : IPv4(str.c_str())
{}

IPv4::IPv4(const std::wstring & str)
    : IPv4(str.c_str())
{}

IPv4::IPv4(byte b1, byte b2, byte b3, byte b4)
    : m_aData{ b1, b2, b3, b4}
{}

IPv4::IPv4(int b1, int b2, int b3, int b4)
    : m_aData{ byte(b1), byte(b2), byte(b3), byte(b4) }
{}

std::string IPv4::toString() const
{
    std::ostringstream oss;
    for (std::size_t i = 0; i < m_aData.size(); ++i)
    {
        if (i > 0)
            oss << ".";
        oss << static_cast<int>(m_aData[i]);
    }
    return oss.str();
}

std::wstring IPv4::toWString() const
{
    std::wostringstream oss;
    for (std::size_t i = 0; i < m_aData.size(); ++i)
    {
        if (i > 0)
            oss << L".";
        oss << static_cast<int>(m_aData[i]);
    }
    return oss.str();
}

IPv4::byte IPv4::operator[](std::size_t idx) const
{
    if (idx > 3)
        throw std::invalid_argument("IPv4: out of range");
    return m_aData[idx];
}

IPv4::byte & IPv4::operator[](std::size_t idx)
{
    if (idx > 3)
        throw std::invalid_argument("IPv4: out of range");
    return m_aData[idx];
}

bool IPv4::operator<(const IPv4 & other) const
{
    if (this == &other)
        return false;

    return m_aData < other.m_aData;
}

bool IPv4::operator==(const IPv4 & other) const
{
    return this == &other || m_aData == other.m_aData;
}

} //namespace ipf
