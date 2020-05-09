//
// Created by akhtyamovpavel on 5/1/20.
//


#include "TreeTestCase.h"
 
FileNode TreeTestCase::my_tree( const std::string& path, bool dirs_only )
{
    return GetTree( path, dirs_only );
}

TEST( TreeTestCase, not_real_path )
{
    EXPECT_THROW( TreeTestCase::my_tree( "/abrafaksusuunderblackflagus", true ), std::invalid_argument );
}

TEST( TreeTestCase, file_not_directory )
{
    EXPECT_THROW( TreeTestCase::my_tree( __FILE__, true ), std::invalid_argument );
}

TEST( TreeTestCase, answer_name )
{
    auto path_ = boost::filesystem::current_path();
    std::string path_string = path_.c_str();
    EXPECT_EQ( path_.filename().string(), TreeTestCase::my_tree( path_string , true ).name );
}

TEST( TreeTestCase, answer_is_dir )
{
    auto path_ = boost::filesystem::current_path();
    std::string path_string = path_.c_str();
    EXPECT_TRUE( TreeTestCase::my_tree( path_string , true ).is_dir );
}

TEST( TreeTestCase, children )
{
    std::string path_ = __FILE__;
    std::string cut_path = path_.substr( 0, path_.rfind( "/" ) );
    cut_path = cut_path.substr( 0, cut_path.rfind( "/" ) );
    auto file = TreeTestCase::my_tree( cut_path , false );
    auto children = file.children;
    std::vector< std::string > children_names;
    for( int i = 0; i < children.size(); ++i )
        children_names.push_back( children[i].name );
    std::sort( children_names.begin(), children_names.end() );
    bool test = children_names[0] == "00-aplusb" && children_names[1] == "01-simple-library" &&
    children_names[2] == "02-tree" && children_names[3] == "03-weather";
    EXPECT_TRUE( test );
}

TEST( TreeTestCase, bool_operator_1 )
{
    std::string path_ = __FILE__;
    std::string cut_path = path_.substr( 0, path_.rfind( "/" ) );
    auto file = GetTree( cut_path, true );
    EXPECT_TRUE( file == file );
}

TEST( TreeTestCase, bool_operator_2 )
{
    std::string path_ = __FILE__;
    std::string cut_path = path_.substr( 0, path_.rfind( "/" ) );
    auto file_1 = GetTree( cut_path, true );
    cut_path = cut_path.substr( 0, cut_path.rfind( "/" ) );
    auto file_2 = GetTree( cut_path, false );
    EXPECT_FALSE( file_1 == file_2 );
}