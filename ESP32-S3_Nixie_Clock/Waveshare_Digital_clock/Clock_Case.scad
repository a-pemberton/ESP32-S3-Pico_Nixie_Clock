/***************************************************************************

Openscad code for Waveshare's Nixie Clock for wireless MCU's.
Copyright (C) 2023  Anthony Pemberton (tony.pemberton.cowroast@gmail.com)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

***************************************************************************/

/*

This partial case design is a plastic replacement case for the Waveshare 'Nixie'
clock. The supplied aluminium case forms an effective faraday shield for any radio
MCU device (e.g. Raspberry Pi Zero-2W or Pico-W, ESP32) which prevents wireless
signals passing through. This means that accurate timekeeping without NTP connectioms
will slowly become inaccurate over time. Also there is no possibility of fitting a
wired ethernet connection if desired.

All dimensions in mm.

*/

echo(version=version());

//-----------------------------------------------------------------------------
// Use a small value to make sure that print errors and part difference()'s are cleanly implemented 
tolerance = 0.01;
// for nice smooth holes
$fn=50;

//-----------------------------------------------------------------------------
// Embossed text options. Uses the Openscad 'text' function 
// Choose a font that looks nice in the box! LiberationSans is the default.
//-----------------------------------------------------------------------------

option_Embossed_Case_Name = "Yes"; //["Yes","No"]
option_Node_Name = (option_Embossed_Case_Name == "Yes") ? true : false;

// Button/USB name strings - keep it short!
power_case_name = "PWR";
mode_case_name = "MODE";
right_case_name = "RIGHT";
left_case_name = "LEFT";
usb_case_name = "USB";
 
Font_Style = "Arial"; //["AndaleMono","ArialMT","Arial Black","Arial","ComicSans","CourierNew","Georgia","Impact","LiberationMono","LiberationSans","LiberationSansNarrow","LiberationSerif","TimesNewRoman","Trebuchet","Verdana","Webdings"]
Font_Size = 2.5;
Font_Type = "Regular"; //["Regular","Bold","Italic","Bold Italic","Black","Oblique","Condensed"]

//-----------------------------------------------------------------------------
// Use projecting spigots (true) to locate PCB's
// or drill holes for self tapping screws (false)
//-----------------------------------------------------------------------------

option_spigots_or_screw_holes = "Spigots"; //["Spigots","holes"]
board_spigots = (option_spigots_or_screw_holes == "Spigots") ? true : false;

//-----------------------------------------------------------------------------
// Select WiFi Antenna Mounting Options - comment unwanted options
// Used with add on long range WiFi antennae as appropriate for MCU type
// selected below, for example the ESP32-CAM. RPi PicoW does not support
// Antenna. Hole is for a standard SMB screw fixing.
//
// Alternatively, provice an optional USB hole for CPU Debugging.
// Large or small Micro B size USB hole depending on USN cable to be used.
//
//-----------------------------------------------------------------------------

// Provide hole in case for SMA mount external antenna
option_case_hole_type = "Small_USB";//["None","SMB_Hole","Small_USB","Large_USB"]

//-----------------------------------------------------------------------------
// Provide a higher case height for a SSD1306 0.91" display bezel
option_SSD1306_Bezel = "YES";//["YES","NO"]

//-----------------------------------------------------------------------------
// Specify the minimum case height (depth).
//-----------------------------------------------------------------------------

option_case_hole = 
  (option_case_hole_type == "None") ? "None" : 
  (option_case_hole_type == "SMB_Hole") ? "SMB_Hole" :
  (option_case_hole_type == "Small_USB") ? "Small_USB" :
  (option_case_hole_type == "Large_USB") ? "Large_USB" : undef;

//-----------------------------------------------------------------------------
// Function to compute securing screw/spigot sizes from table below
// Screw size is slected depending on board type
//-----------------------------------------------------------------------------
function find_size(MyString) = 
  (MyString == "null") ? 0  :
  (MyString == "M1")   ? 1  :
  (MyString == "M1.2") ? 2  :
  (MyString == "M1.4") ? 3  :
  (MyString == "M1.6") ? 4  :
  (MyString == "M1.8") ? 5  :
  (MyString == "M2")   ? 6  :
  (MyString == "M2.3") ? 7  :
  (MyString == "M2.5") ? 8  :
  (MyString == "M2.6") ? 9  :
  (MyString == "M3")   ? 10 :
  (MyString == "M3.5") ? 11 : 0;

// Column selection values for above tables
hole_dia = 1;
nut_e_min = 2;
nut_depth = 4;
screw_cap_dia = 3;
screw_cap_depth = 4;


//-----------------------------------------------------------------------------
// Table of metric cheese head screws from ISO 965
// Table incomplete! Some dummies added for unknown sizes
//-----------------------------------------------------------------------------
METRIC_SCREW_DMENSIONS = [ 
//   index       hole diameter    d1max    d2max     kmax 
    [   0,                   0,       0,       0,       0   ],   // Dummy offset
    [   1,   1.0+(tolerance*2),   1.000,   2.000,   0.700   ],   // M1
    [   2,   1.2+(tolerance*2),   1.200,   2.300,   0.800   ],   // M1.2
    [   3,   1.4+(tolerance*2),   1.400,   2.600,   0.900   ],   // M1.4
    [   4,   1.6+(tolerance*2),   1.600,   3.000,   1.000   ],   // M1.6
    [   5,   1.8+(tolerance*2),   1.800,   3.400,   1.200   ],   // M1.8
    [   6,   2.0+(tolerance*2),   2.000,   3.800,   1.300   ],   // M2
    [   7,   2.3+(tolerance*2),   0.000,   0.000,   0.000   ],   // M2.3
    [   8,   2.5+(tolerance*2),   2.500,   4.500,   1.600   ],   // M2.5
    [   9,   2.5+(tolerance*2),   0.000,   0.000,   0.000   ],   // M2.6
    [  10,   3.0+(tolerance*2),   3.000,   5.500,   2.000   ],   // M3
    [  11,   3.5+(tolerance*2),   3.500,   6.000,   2.400   ]    // M3.5
];

//-----------------------------------------------------------------------------
// Optional SSD1306 0.91" bezel appeture dimensions
//-----------------------------------------------------------------------------

SSD1306_0point91_holder_l = 43.50;
SSD1306_0point91_holder_w = 17.50;
SSD1306_0point91_holder_h = 5.00;
SSD1306_0point91_bezel_l = 40.50;
SSD1306_0point91_bezel_w = 14.50;
SSD1306_0point91_bezel_h = 2.00;

// Redefine case height
option_case_height_extension = 
  (option_SSD1306_Bezel == "YES") ? SSD1306_0point91_bezel_w : 0;

//-----------------------------------------------------------------------------
// Fixed case length definitions 
//-----------------------------------------------------------------------------

case_wall_thickness = 1.5;

outside_case_l = 195;
outside_case_w = 74.5;
outside_case_h = 26.5 + option_case_height_extension;

// Set initial case position on screen
outside_case_pos_l = 0;
outside_case_pos_w = 0;
outside_case_pos_h = 0;

inside_case_l = outside_case_l-(case_wall_thickness*2);
inside_case_w = outside_case_w-(case_wall_thickness*2);
inside_case_h = outside_case_h;

inside_case_pos_l = outside_case_pos_l+case_wall_thickness;
inside_case_pos_w = outside_case_pos_w+case_wall_thickness;
inside_case_pos_h = outside_case_pos_h+case_wall_thickness;

//-----------------------------------------------------------------------------
// Define case base cutout
//-----------------------------------------------------------------------------

base_case_cutout_l = (outside_case_l/2)-20;
base_case_cutout_w = outside_case_w-36.5;
base_case_cutout_h = case_wall_thickness+(tolerance*2);

base_case_cutout_near_pos_l = outside_case_pos_l+20;
//base_case_cutout_far_pos_l = outside_case_pos_l+(outside_case_l/2)+10;
base_case_cutout_pos_w = outside_case_pos_w+18.25;
base_case_cutout_pos_h = -tolerance;

//-----------------------------------------------------------------------------
// Define PCB Support Pillars - Make them bigger than original
// because they are platic rather than metal
//-----------------------------------------------------------------------------

support_pillar_dia = 8;
support_pillar_len = (14+option_case_height_extension+(case_wall_thickness/2))-inside_case_pos_h;

support_pillar_near_pos_l = outside_case_pos_l+9.5;
support_pillar_left_pos_w = outside_case_pos_w+12;
support_pillar_far_pos_l = outside_case_pos_l+(outside_case_l-9.5);
support_pillar_right_pos_w = outside_case_pos_w+(outside_case_w-12);

support_pillar_pos_h = inside_case_pos_h-(case_wall_thickness/2);

// drill holes for M3 Self Tap screws
support_pillar_screwhole_dia = METRIC_SCREW_DMENSIONS[find_size("M3")][hole_dia] - 0.15;

//-----------------------------------------------------------------------------
// Define and locate holes for 'PWR,'MODE',RIGHT','LEFT' buttons
// 
//-----------------------------------------------------------------------------

buttonhole_dia = 5;
buttonhole_h = case_wall_thickness + (tolerance*2);

power_buttonhole_pos_l = 40.25;
power_buttonhole_pos_w = -tolerance;
power_buttonhole_pos_h = outside_case_h-7.45;

mode_buttonhole_pos_l = 52.25;
mode_buttonhole_pos_w = -tolerance;
mode_buttonhole_pos_h = outside_case_h-7.45;

right_buttonhole_pos_l = 64.25;
right_buttonhole_pos_w = -tolerance;
right_buttonhole_pos_h = outside_case_h-7.45;

left_buttonhole_pos_l = 76.25;
left_buttonhole_pos_w = -tolerance;
left_buttonhole_pos_h = outside_case_h-7.45;

usb_hole_dia = 5;
usb_hole_len = 7.25;
usb_hole_h = case_wall_thickness + (tolerance*2);

usb_hole_pos_l = 94.25;
usb_hole_pos_w = -tolerance;
usb_hole_pos_h = outside_case_h-9.5;

// Text Positions on case
text_depth = case_wall_thickness/2;
char_spacing = 1;

power_case_pos_l = power_buttonhole_pos_l;
power_case_pos_w = text_depth-tolerance;
power_case_pos_h = power_buttonhole_pos_h + (buttonhole_dia/2) +1.5;
mode_case_pos_l = mode_buttonhole_pos_l;
mode_case_pos_w = text_depth-tolerance;
mode_case_pos_h = power_buttonhole_pos_h + (buttonhole_dia/2) +1.5;
right_case_pos_l = right_buttonhole_pos_l;
right_case_pos_w = text_depth-tolerance;
right_case_pos_h = power_buttonhole_pos_h + (buttonhole_dia/2) +1.5;
left_case_pos_l = left_buttonhole_pos_l;
left_case_pos_w = text_depth-tolerance;
left_case_pos_h = power_buttonhole_pos_h + (buttonhole_dia/2) +1.5;
usb_case_pos_l = usb_hole_pos_l+(usb_hole_len/2);
usb_case_pos_w = text_depth-tolerance;
usb_case_pos_h = power_buttonhole_pos_h + (buttonhole_dia/2) +1.5;

// Antenna hole params (standard WiFi antenna with SMA mounting)
wifi_antenna_hole_dia = 6.5; // For SMB coax fitting
end_antenna_hole_l = case_wall_thickness +(tolerance*2);
end_antenna_hole_pos_l = -tolerance;
end_antenna_hole_pos_w = outside_case_w/2;
end_antenna_hole_pos_h = (wifi_antenna_hole_dia/2) + (case_wall_thickness*3);

Small_USB_hole_l = case_wall_thickness +(tolerance*2);
Small_USB_hole_w = 12;
Small_USB_hole_h = 7.25;
Small_USB_hole_pos_l = -tolerance;
Small_USB_hole_pos_w = (outside_case_w-Small_USB_hole_w)/2;
Small_USB_hole_pos_h = 2.5+option_case_height_extension;

Large_USB_hole_l = case_wall_thickness +(tolerance*2);
Large_USB_hole_w = 14;
Large_USB_hole_h = 10;
Large_USB_hole_pos_l = -tolerance;
Large_USB_hole_pos_w = (outside_case_w-Large_USB_hole_w)/2;
Large_USB_hole_pos_h = 2.5+option_case_height_extension;

// Optional SSD1306 0.91" bezel appeture dimensions
SSD1306_0point91_case_hole_l = SSD1306_0point91_bezel_l + (tolerance*5);
SSD1306_0point91_case_hole_w = case_wall_thickness +(tolerance*2);
SSD1306_0point91_case_hole_h = SSD1306_0point91_bezel_w + (tolerance*5);
SSD1306_0point91_case_hole_pos_l = (outside_case_l/2)-(SSD1306_0point91_case_hole_l/2);
SSD1306_0point91_case_hole_pos_w = outside_case_w - (SSD1306_0point91_case_hole_w - tolerance);
SSD1306_0point91_case_hole_pos_h = 5.00;

//-----------------------------------------------------------------------------


// overall case dimensions 
// Position basic case
translate([outside_case_pos_l, outside_case_pos_w, outside_case_pos_h])
{
  union() {
//generate empty box with cutouts
    difference()
    {
      cube([outside_case_l, outside_case_w, outside_case_h]);
      translate([inside_case_pos_l,inside_case_pos_w,inside_case_pos_h])
        cube([inside_case_l,inside_case_w,inside_case_h]);

      translate([base_case_cutout_near_pos_l,base_case_cutout_pos_w,base_case_cutout_pos_h])
        minkowski() {
          cube([base_case_cutout_l,base_case_cutout_w,base_case_cutout_h]);
          cylinder(r=2,h=1);
        }
/*
      translate([base_case_cutout_far_pos_l,base_case_cutout_pos_w,base_case_cutout_pos_h])
        minkowski() {
          cube([base_case_cutout_l,base_case_cutout_w,base_case_cutout_h]);
          cylinder(r=2,h=1);
        }
*/        
// Through holes for PCB pillars
      translate([support_pillar_near_pos_l,support_pillar_left_pos_w,-tolerance])
        cylinder(h=(case_wall_thickness+tolerance)*2,d=support_pillar_screwhole_dia);
 
      translate([support_pillar_near_pos_l,support_pillar_right_pos_w,-tolerance])
        cylinder(h=(case_wall_thickness+tolerance)*2,d=support_pillar_screwhole_dia);

      translate([support_pillar_far_pos_l,support_pillar_left_pos_w,-tolerance])
        cylinder(h=(case_wall_thickness+tolerance)*2,d=support_pillar_screwhole_dia);

      translate([support_pillar_far_pos_l,support_pillar_right_pos_w,-tolerance])
        cylinder(h=(case_wall_thickness+tolerance)*2,d=support_pillar_screwhole_dia);
// Holes for PCB push buttons 
      translate([power_buttonhole_pos_l,power_buttonhole_pos_w,power_buttonhole_pos_h]) rotate([270,0,0])
        cylinder(h=buttonhole_h,d=buttonhole_dia);

      translate([mode_buttonhole_pos_l,mode_buttonhole_pos_w,mode_buttonhole_pos_h]) rotate([270,0,0])
        cylinder(h=buttonhole_h,d=buttonhole_dia);

      translate([right_buttonhole_pos_l,right_buttonhole_pos_w,right_buttonhole_pos_h]) rotate([270,0,0])
        cylinder(h=buttonhole_h,d=buttonhole_dia);

      translate([left_buttonhole_pos_l,left_buttonhole_pos_w,left_buttonhole_pos_h]) rotate([270,0,0])
        cylinder(h=buttonhole_h,d=buttonhole_dia);
// Hole for USB C socket
      translate([usb_hole_pos_l,usb_hole_pos_w,usb_hole_pos_h]) rotate([270,0,0])
        linear_extrude(usb_hole_h) hull() {
              translate([usb_hole_len,0,0]) circle(usb_hole_dia/2);
              circle(usb_hole_dia/2);
        }
 
// Add optional device name cutouts to case
      if (option_Node_Name) {
        generate_node_name_text(power_case_pos_l,power_case_pos_w,power_case_pos_h,power_case_name,[0,0,0]);   
        generate_node_name_text(mode_case_pos_l,mode_case_pos_w,mode_case_pos_h,mode_case_name,[0,0,0]);   
        generate_node_name_text(right_case_pos_l,right_case_pos_w,right_case_pos_h,right_case_name,[0,0,0]);   
        generate_node_name_text(left_case_pos_l,left_case_pos_w,left_case_pos_h,left_case_name,[0,0,0]);   
        generate_node_name_text(usb_case_pos_l,usb_case_pos_w,usb_case_pos_h,usb_case_name,[0,0,0]);   
      }

// Add end antenna mount hole if requested and if possible due to other end limitations (vents or fan?)
      if (option_case_hole == "SMB_Hole") {
        translate([end_antenna_hole_pos_l,end_antenna_hole_pos_w,end_antenna_hole_pos_h])
          rotate([0,90,0])cylinder(d=wifi_antenna_hole_dia,end_antenna_hole_l);
      }

// Add optional Small MicroB USB aperture for debugging
      if (option_case_hole == "Small_USB") {
        translate([Small_USB_hole_pos_l,Small_USB_hole_pos_w,Small_USB_hole_pos_h])
          cube([Small_USB_hole_l,Small_USB_hole_w,Small_USB_hole_h]);
      }

// Add optional Large MicroB USB aperture for debugging
      if (option_case_hole == "Large_USB") {
        translate([Large_USB_hole_pos_l,Large_USB_hole_pos_w,Large_USB_hole_pos_h])
          cube([Large_USB_hole_l,Large_USB_hole_w,Large_USB_hole_h]);
      }

// Optional - Cut hole for SSD1306 0.91" OLED display
      if (option_SSD1306_Bezel == "YES") {
        translate([SSD1306_0point91_case_hole_pos_l,SSD1306_0point91_case_hole_pos_w,SSD1306_0point91_case_hole_pos_h])
          cube([SSD1306_0point91_case_hole_l,SSD1306_0point91_case_hole_w,SSD1306_0point91_case_hole_h]);
      }
      
    } // End of difference()

    translate([support_pillar_near_pos_l,support_pillar_left_pos_w,support_pillar_pos_h])
      difference() {
        cylinder(h=support_pillar_len,d=support_pillar_dia);
        translate([0,0,-(case_wall_thickness*2)])
          cylinder(h=support_pillar_len+((case_wall_thickness+tolerance)*2),d=support_pillar_screwhole_dia);
      }

    translate([support_pillar_near_pos_l,support_pillar_right_pos_w,support_pillar_pos_h])
      difference() {
        cylinder(h=support_pillar_len,d=support_pillar_dia);
        translate([0,0,-(case_wall_thickness*2)])
          cylinder(h=support_pillar_len+((case_wall_thickness+tolerance)*2),d=support_pillar_screwhole_dia);
      }

    translate([support_pillar_far_pos_l,support_pillar_left_pos_w,support_pillar_pos_h])
      difference() {
        cylinder(h=support_pillar_len,d=support_pillar_dia);
        translate([0,0,-(case_wall_thickness*2)])
          cylinder(h=support_pillar_len+((case_wall_thickness+tolerance)*2),d=support_pillar_screwhole_dia);
      }

    translate([support_pillar_far_pos_l,support_pillar_right_pos_w,support_pillar_pos_h])
      difference() {
        cylinder(h=support_pillar_len,d=support_pillar_dia);
        translate([0,0,-(case_wall_thickness*2)])
          cylinder(h=support_pillar_len+((case_wall_thickness+tolerance)*2),d=support_pillar_screwhole_dia);
      }
  } 
}

// Fit the text into the area based on the length
module generate_node_name_text(pos_l,pos_w,pos_h,t,rotation) {
  echo("text_depth = ",text_depth);
  translate([pos_l,pos_w,pos_h])
    rotate(90,[1,0,0]) linear_extrude(text_depth, center = false, convexity = 4)
      rotate(rotation) text(t, size = Font_Size, halign = "center",valign = "center",
           spacing = char_spacing,
           font = Font_Style,
           $fn = 25);
}

translate([0,outside_case_w+5,0]) rotate([0,0,0]) {
import("/home/tonyp/Documents/3D_Models/SSD1306_OLED_frame_cover_128x32_0.91/files/SSD1306_FRAME_2point0_mm.3mf", convexity=3);
}