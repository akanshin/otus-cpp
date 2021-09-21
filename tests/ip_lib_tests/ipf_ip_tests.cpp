#include "precompiled.h"
#include "ipf_ip.h"

TEST(IPv4Test, default_constructor)
{
    ipf::IPv4 def;
    ASSERT_EQ(ipf::IPv4::byte(127), def[0]);
    ASSERT_EQ(ipf::IPv4::byte(0), def[1]);
    ASSERT_EQ(ipf::IPv4::byte(0), def[2]);
    ASSERT_EQ(ipf::IPv4::byte(1), def[3]);
}

TEST(IPv4Test, constructor_const_char_ptr)
{
    ipf::IPv4 def{ "1.2.3.4" };
    ASSERT_EQ(ipf::IPv4::byte(1), def[0]);
    ASSERT_EQ(ipf::IPv4::byte(2), def[1]);
    ASSERT_EQ(ipf::IPv4::byte(3), def[2]);
    ASSERT_EQ(ipf::IPv4::byte(4), def[3]);
}

TEST(IPv4Test, constructor_const_wchar_ptr)
{
    ipf::IPv4 def{ L"1.2.3.4" };
    ASSERT_EQ(ipf::IPv4::byte(1), def[0]);
    ASSERT_EQ(ipf::IPv4::byte(2), def[1]);
    ASSERT_EQ(ipf::IPv4::byte(3), def[2]);
    ASSERT_EQ(ipf::IPv4::byte(4), def[3]);
}

TEST(IPv4Test, constructor_const_string_ref)
{
    ipf::IPv4 def{ std::string("1.2.3.4") };
    ASSERT_EQ(ipf::IPv4::byte(1), def[0]);
    ASSERT_EQ(ipf::IPv4::byte(2), def[1]);
    ASSERT_EQ(ipf::IPv4::byte(3), def[2]);
    ASSERT_EQ(ipf::IPv4::byte(4), def[3]);
}

TEST(IPv4Test, constructor_const_wstring_ref)
{
    ipf::IPv4 def{ std::wstring(L"1.2.3.4") };
    ASSERT_EQ(ipf::IPv4::byte(1), def[0]);
    ASSERT_EQ(ipf::IPv4::byte(2), def[1]);
    ASSERT_EQ(ipf::IPv4::byte(3), def[2]);
    ASSERT_EQ(ipf::IPv4::byte(4), def[3]);
}

TEST(IPv4Test, constructor_4_bytes)
{
    ipf::IPv4 def{ ipf::IPv4::byte(1), ipf::IPv4::byte(2), ipf::IPv4::byte(3), ipf::IPv4::byte(4) };
    ASSERT_EQ(ipf::IPv4::byte(1), def[0]);
    ASSERT_EQ(ipf::IPv4::byte(2), def[1]);
    ASSERT_EQ(ipf::IPv4::byte(3), def[2]);
    ASSERT_EQ(ipf::IPv4::byte(4), def[3]);
}

TEST(IPv4Test, constructor_4_ints)
{
    ipf::IPv4 def{ 1, 2, 3, 4 };
    ASSERT_EQ(ipf::IPv4::byte(1), def[0]);
    ASSERT_EQ(ipf::IPv4::byte(2), def[1]);
    ASSERT_EQ(ipf::IPv4::byte(3), def[2]);
    ASSERT_EQ(ipf::IPv4::byte(4), def[3]);
}

TEST(IPv4Test, constructor_copy)
{
    ipf::IPv4 def{ 1, 2, 3, 4 };
    ipf::IPv4 copy{ def };
    ASSERT_EQ(ipf::IPv4::byte(1), copy[0]);
    ASSERT_EQ(ipf::IPv4::byte(2), copy[1]);
    ASSERT_EQ(ipf::IPv4::byte(3), copy[2]);
    ASSERT_EQ(ipf::IPv4::byte(4), copy[3]);
}

TEST(IPv4Test, constructor_move)
{
    ipf::IPv4 def{ 1, 2, 3, 4 };
    ipf::IPv4 moved{ std::move(def) };
    ASSERT_EQ(ipf::IPv4::byte(1), moved[0]);
    ASSERT_EQ(ipf::IPv4::byte(2), moved[1]);
    ASSERT_EQ(ipf::IPv4::byte(3), moved[2]);
    ASSERT_EQ(ipf::IPv4::byte(4), moved[3]);
}

TEST(IPv4Test, operator_assign_ref)
{
    ipf::IPv4 def{ 1, 2, 3, 4 };
    ipf::IPv4 copy = def;
    ASSERT_EQ(ipf::IPv4::byte(1), copy[0]);
    ASSERT_EQ(ipf::IPv4::byte(2), copy[1]);
    ASSERT_EQ(ipf::IPv4::byte(3), copy[2]);
    ASSERT_EQ(ipf::IPv4::byte(4), copy[3]);
}

TEST(IPv4Test, operator_assign_move)
{
    ipf::IPv4 def{ 1, 2, 3, 4 };
    ipf::IPv4 moved = std::move(def);
    ASSERT_EQ(ipf::IPv4::byte(1), moved[0]);
    ASSERT_EQ(ipf::IPv4::byte(2), moved[1]);
    ASSERT_EQ(ipf::IPv4::byte(3), moved[2]);
    ASSERT_EQ(ipf::IPv4::byte(4), moved[3]);
}

TEST(IPv4Test, toString)
{
    ipf::IPv4 ip{ 192, 168, 1, 10 };
    ASSERT_EQ("192.168.1.10", ip.toString());
}

TEST(IPv4Test, toWString)
{
    ipf::IPv4 ip{ 192, 168, 1, 10 };
    ASSERT_EQ(L"192.168.1.10", ip.toWString());
}

TEST(IPv4Test, operator_less)
{
    ipf::IPv4 ip1{ 192, 168, 1, 10 };
    ipf::IPv4 ip2{ 192, 168, 1, 20 };
    ipf::IPv4 ip3{ 255, 255, 255, 0 };
    ASSERT_TRUE(ip1 < ip2);
    ASSERT_FALSE(ip2 < ip1);
    ASSERT_TRUE(ip2 < ip3);
    ASSERT_FALSE(ip3 < ip2);
    ASSERT_TRUE(ip1 < ip3);
    ASSERT_FALSE(ip3 < ip1);
    ASSERT_FALSE(ip1 < ip1);
}

TEST(IPv4Test, operator_equal)
{
    ipf::IPv4 ip1{ 192, 168, 1, 10 };
    ipf::IPv4 ip2{ 192, 168, 1, 20 };
    ipf::IPv4 ip3{ 255, 255, 255, 0 };
    ipf::IPv4 ip4{ 192, 168, 1, 20 };
    ASSERT_FALSE(ip1 == ip2);
    ASSERT_FALSE(ip2 == ip1);
    ASSERT_TRUE(ip2 == ip4);
    ASSERT_FALSE(ip3 == ip2);
    ASSERT_FALSE(ip1 == ip3);
    ASSERT_FALSE(ip3 == ip1);
    ASSERT_TRUE(ip1 == ip1);
}

TEST(IPv4Test, std_hash)
{
    ipf::IPv4 ip1{ 192, 168, 1, 10 };
    ipf::IPv4 ip2{ 192, 168, 1, 20 };
    ipf::IPv4 ip3{ 255, 255, 255, 0 };
    ipf::IPv4 ip4{ 192, 168, 1, 20 };
    
    std::unordered_set<ipf::IPv4> s;
    ASSERT_TRUE(s.emplace(ip1).second);
    ASSERT_TRUE(s.emplace(ip2).second);
    ASSERT_TRUE(s.emplace(ip3).second);
    ASSERT_FALSE(s.emplace(ip4).second);
}
