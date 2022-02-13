EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Motor:Motor_DC M1
U 1 1 6196066A
P 5650 3700
F 0 "M1" H 5808 3696 50  0000 L CNN
F 1 "Motor_DC" H 5808 3605 50  0000 L CNN
F 2 "Connector:Banana_Jack_2Pin" H 5650 3610 50  0001 C CNN
F 3 "~" H 5650 3610 50  0001 C CNN
	1    5650 3700
	1    0    0    -1  
$EndComp
$Comp
L Device:Battery BT1
U 1 1 61963284
P 5150 3500
F 0 "BT1" V 4905 3500 50  0000 C CNN
F 1 "Battery 12V" V 4996 3500 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 5150 3560 50  0001 C CNN
F 3 "~" V 5150 3560 50  0001 C CNN
	1    5150 3500
	0    1    1    0   
$EndComp
$Comp
L Device:Fuse F1
U 1 1 61964673
P 5500 3500
F 0 "F1" V 5303 3500 50  0000 C CNN
F 1 "Fuse" V 5394 3500 50  0000 C CNN
F 2 "Fuse:Fuse_1806_4516Metric_Pad1.57x1.80mm_HandSolder" V 5430 3500 50  0001 C CNN
F 3 "~" H 5500 3500 50  0001 C CNN
	1    5500 3500
	0    1    1    0   
$EndComp
$Comp
L Device:R R10
U 1 1 6196B1BC
P 6300 3650
F 0 "R10" H 6370 3696 50  0000 L CNN
F 1 "2.2kΩ" H 6370 3605 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 6230 3650 50  0001 C CNN
F 3 "~" H 6300 3650 50  0001 C CNN
	1    6300 3650
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D5
U 1 1 6196E4FC
P 6300 3950
F 0 "D5" H 6293 4166 50  0000 C CNN
F 1 "LED" H 6293 4075 50  0000 C CNN
F 2 "Diode_THT:D_DO-201AD_P15.24mm_Horizontal" H 6300 3950 50  0001 C CNN
F 3 "~" H 6300 3950 50  0001 C CNN
	1    6300 3950
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6300 3500 5650 3500
Connection ~ 5650 3500
Wire Wire Line
	5650 4000 5650 4200
Wire Wire Line
	5650 4200 6300 4200
Wire Wire Line
	6300 4200 6300 4100
Wire Wire Line
	4950 3500 4950 4200
$Comp
L Switch:SW_DIP_x01 SW1
U 1 1 620AF7C3
P 5250 4200
F 0 "SW1" H 5250 4467 50  0000 C CNN
F 1 "SW_DIP_x01" H 5250 4376 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" H 5250 4200 50  0001 C CNN
F 3 "~" H 5250 4200 50  0001 C CNN
	1    5250 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	5550 4200 5650 4200
Connection ~ 5650 4200
$EndSCHEMATC
