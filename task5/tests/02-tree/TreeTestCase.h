//
// Created by akhtyamovpavel on 5/1/20.
//


#pragma once

#include <gtest/gtest.h>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem.hpp>
#include "Tree.h"
#include <algorithm>

class TreeTestCase : public ::testing::Test {
public:
    static FileNode my_tree( const std::string& path, bool dirs_only );
    
};


