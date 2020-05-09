//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#include "WeatherTestCase.h"

using ::testing:: Return;


TEST( WeatherTestCase, set_api )
{
    WeatherMock weather;
    EXPECT_NO_THROW( weather.SetApiKey("abrafaksusunderblackflagus"));
}

TEST( WeatherTestCase, GetResponseForCity_not_existing_city )
{
    cpr::Response my_response;
    my_response.status_code = 0;
    WeatherMock weather;
    EXPECT_CALL( weather, Get( "abrafaksusunderblackflagus" ) ).Times(1).WillOnce( Return( my_response ) );
    EXPECT_THROW( weather.GetResponseForCity( "abrafaksusunderblackflagus" ), std::invalid_argument );
}

TEST( WeatherTestCase, GetResponseForCity_json )
{
    WeatherMock weather;
    cpr::Response my_response;
    my_response.status_code = 200;
    my_response.text = "{\"list\" : [ { \"main\" : { \"temp\" : 21 } } ] }";
    EXPECT_CALL( weather, Get( "Amsterdam" ) ).Times(1).WillOnce( Return ( my_response ) );
    json j3 = weather.GetResponseForCity( "Amsterdam" );
    EXPECT_EQ( j3.size(), 1 );
}

TEST( WeatherTestCase, get_temprature )
{
    WeatherMock weather;
    cpr::Response my_response;
    my_response.status_code = 200;
    my_response.text = "{\"list\" : [ { \"main\" : { \"temp\" : 21 } } ] }";
    EXPECT_CALL( weather, Get( "Amsterdam" ) ).Times(1).WillOnce( Return ( my_response ) );
    float temperature = weather.GetTemperature( "Amsterdam" );
    EXPECT_EQ( temperature, 21.0 );
}

TEST( WeatherTestCase, find_diff )
{
    WeatherMock weather;
    cpr::Response my_response;
    my_response.status_code = 200;
    my_response.text = "{\"list\" : [ { \"main\" : { \"temp\" : 21 } } ] }";
    EXPECT_CALL( weather, Get( "Paris" ) ).Times(1).WillOnce( Return ( my_response ) );
    EXPECT_CALL( weather, Get( "Rome" ) ).Times(1).WillOnce( Return ( my_response ) );

    EXPECT_EQ(0, weather.FindDiffBetweenTwoCities( "Paris", "Rome" ) );
}

TEST( WeatherTestCase, string_dif )
{
    WeatherMock weather;
    cpr::Response my_response;
    my_response.status_code = 200;
    my_response.text = "{\"list\" : [ { \"main\" : { \"temp\" : 21 } } ] }";
    EXPECT_CALL( weather, Get( "Vladivostok" ) ).Times(1).WillOnce( Return ( my_response ) );
    EXPECT_CALL( weather, Get( "Barselona" ) ).Times(1).WillOnce( Return ( my_response ) );

    EXPECT_EQ( "Weather in Vladivostok is warmer than in Barselona by 0 degrees", 
    weather.GetDifferenceString( "Vladivostok", "Barselona" ) );
}

TEST( WeatherTestCase, string_diff_reversed )
{
    WeatherMock weather;
    cpr::Response Havanna, Helsinki;
    Helsinki.status_code = 200;
    Havanna.status_code = 200;
    Helsinki.text = "{\"list\" : [ { \"main\" : { \"temp\" : 21 } } ] }";
    Havanna.text = "{\"list\" : [ { \"main\" : { \"temp\" : 31 } } ] }";
    EXPECT_CALL( weather, Get( "Helsinki" ) ).Times(1).WillOnce( Return ( Helsinki ) );
    EXPECT_CALL( weather, Get( "Havanna" ) ).Times(1).WillOnce( Return ( Havanna ) );

    EXPECT_EQ("Weather in Helsinki is colder than in Havanna by 10 degrees", 
    weather.GetDifferenceString( "Helsinki", "Havanna" ) );
}