// vscpautomation.h
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version
// 2 of the License, or (at your option) any later version.
// 
// This file is part of the VSCP (http://www.vscp.org) 
//
// Copyright (C) 2000-2014 
// Ake Hedman, Paradise of the Frog, <akhe@paradiseofthefrog.com>
// 
// This file is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this file see the file COPYING.  If not, write to
// the Free Software Foundation, 59 Temple Place - Suite 330,
// Boston, MA 02111-1307, USA.
//



#if !defined(VSCPAUTOMATION__INCLUDED_)
#define VSCPAUTOMATION__INCLUDED_



///////////////////////////////////////////////////////////////////////////////
// Class that holds one VSCP vautomation
//

class CVSCPAutomation {

public:

	/// Constructor
	CVSCPAutomation(void);

	// Destructor
	virtual ~CVSCPAutomation(void);


    /*!

    */
    static double FNday(int y, int m, int d, float h);


    /*!

    */
    static double FNrange(double x);

    /*!

    */
    static double f0(double lat, double declin);


    /*!

    */
    static double f1(double lat, double declin);

    /*!

    */
    static double FNsun(double d);


    /*!

    */
    static void convert2HourMinute( double floatTime, int *pHours, int *pMinutes );

    /*!
        Calculate Sunset/Sunrice etc   
    */
    void calcSun( void );

    /*!
        Do automation work
    */
    void doWork( void );

public:

    /// Zone that automation server belongs to
    uint8_t m_zone;

    /// Subzone that automation server belongs to
    uint8_t m_subzone;

    /// Logitude for this server
    double m_longitude;

    /// Latitude for this server
    double m_latitude;

    /*!
        Timezone for this computer
        GMT = 0;
    */
    double m_timezone;

    /*!
        Set to true for  periodic CLASS1.PROTOCOL, Type=1 (Segment Status Heartbeat) 
        event to be sent from the daemon. The interval between events is set in seconds.
    */
    bool m_bSegmentControllerHeartbeat; 

    /*!
        Seconds between Segment Status Heartbeat
    */
    long m_intervalSegmentControllerHeartbeat;   // long because of .toLong

    /*!
        Enable/disable heartbeat.
    */
    bool m_bHeartBeatEvent;

    /*!
        Interval in seconds for heartbeats
    */
    long m_intervalHeartBeat;                   // long because of .toLong

    /*!
        Start date time when daylight saving time starts. When daylight saving time is in 
        effect the zone value will be increase with one for all calculations. Date/Time should 
        be on the form YY-MM-DD HH:MM:SS
    */
    wxDateTime m_daylightsavingtimeStart;

    /*!
        Start date time when daylight saving time starts. When daylight saving time is in 
        effect the zone value will be increase with one for all calculations. Date/Time should 
        be on the form YY-MM-DD HH:MM:SS
    */
    wxDateTime m_daylightsavingtimeEnd;

    /*!
        Enable/disable the CLASS1.INFORMATION, Type=52 (Civil sunrise twilight time) to be sent. 
        Longitude, latitude and timezone must be set for this to work correctly.
    */
    bool m_bSunRiseEvent;

    /*!
        Enable/disable the CLASS1.INFORMATION, Type=52 (Civil sunrise twilight time) to be sent. 
        Longitude, latitude and timezone must be set for this to work correctly.
    */
    bool m_bSunRiseTwilightEvent;

    /*!
        Enable/disable the CLASS1.INFORMATION, Type=45 (Sunset) to be sent. 
        Longitude, latitude and timezone must be set for this to work correctly.
    */
    bool m_bSunSetEvent;

    /*!
        Enable/disable the CLASS1.INFORMATION, Type=53 (Civil sunset twilight time) 
        to be sent. Longitude, latitude and timezone must be set for this to work correctly.
    */
    bool m_bSunSetTwilightEvent;

 private:

     /*!
        calculations holders.
        ---------------------
        Structure holding calculated values
        use convert2HourMinute to convert from
        double to hour/minutes
     */
    double m_declination;
    double m_daylength;               // hours/minutes
    double m_SunMaxAltitude;

    /*!
        Done every 24 hours and at startup
    */
    wxDateTime m_lastCalculation;

    wxDateTime m_civilTwilightSunriseTime;
    wxDateTime m_civilTwilightSunriseTime_sent;

    wxDateTime m_SunriseTime;
    wxDateTime m_SunriseTime_sent;
    
    wxDateTime m_SunsetTime;
    wxDateTime m_SunsetTime_sent;
    
    wxDateTime m_civilTwilightSunsetTime;
    wxDateTime m_civilTwilightSunsetTime_sent;
    
    wxDateTime m_noonTime;
    wxDateTime m_noonTime_sent;

    /*!
        Set tto true when calculations has been done and
        time is 12:00
    */
    bool m_bCalulationHasBeenDone;

private:

};


#endif