/*
Copyright (c) 2014-2015 NicoHood
See the readme for credit to other people.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#include "BrailleDisplay.h"


static const uint8_t _hidMultiReportDescriptorConsumer[] PROGMEM = {
0x05,0x41,//UsagePage(Braille)
0x09,0x01,//USAGE(BrailleDisplay)
0xA1,0x01,//Collection(Application)
0x1A,0x01,0x02,//UsageMinimum(BrailleKeyboardDot1\)
0x2A,0x08,0x02,//UsageMaximum(BrailleKeyboardDot8)
0x75,0x01,//ReportSize(1)
0x95,0x08,//ReportCount(8)
0x15,0x00,//LogicalMinimum(0)
0x25,0x01,//LogicalMaximum(1)
0x81,0x02,//Input(Data,Var,Abs,NoWrap,Linear,PreferredState,NoNullPosition)
0x75,0x01,//ReportSize(1)
0x95,0x01,//ReportCount(1)
0x81,0x03,//Input(Const,Var,Abs,NoWrap,Linear,PreferredState,NoNullPosition)
0x0A,0x0D,0x02,//Usage(BrailleLeftControls)
0xA1,0x02,//Collection(Logical)
0x05,0x09,//UsagePage(Button)
0x19,0x01,//UsageMinimum(Button1)
0x29,0x03,//UsageMaximum(Button3)
0x75,0x01,//ReportSize(1)
0x95,0x03,//ReportCount(3)
0x15,0x00,//LogicalMinimum(0)
0x25,0x01,//LogicalMaximum(1)
0x81,0x02,//Input(Data,Var,Abs,NoWrap,Linear,PreferredState,NoNullPosition)
0xC0,//EndCollection0x05,0x41,//UsagePage(Braille)
0x0A,0x0E,0x02,//Usage(BrailleRightControls)
0xA1,0x02,//Collection(Logical)
0x05,0x09,//UsagePage(Button)
0x19,0x01,//UsageMinimum(Button1)
0x29,0x03,//UsageMaximum(Button3)
0x75,0x01,//ReportSize(1)
0x95,0x03,//ReportCount(3)
0x15,0x00,//LogicalMinimum(0)
0x25,0x01,//LogicalMaximum(1)
0x81,0x02,//Input(Data,Var,Abs,NoWrap,Linear,PreferredState,NoNullPosition)
0xC0,//EndCollection0x75,0x02,//ReportSize(2)
0x95,0x01,//ReportCount(1)
0x81,0x03,//Input(Const,Var,Abs,NoWrap,Linear,PreferredState,NoNullPosition) //2bitpad0x05,0x41,//UsagePage(Braille)
0x0A,0x0C,0x02,//Usage(BrailleFaceControls)
0xA1,0x02,//Collection(Logical)
0x05,0x09,//UsagePage(Button)
0x19,0x01,//UsageMinimum(Button1)
0x29,0x03,//UsageMaximum(Button4)
0x75,0x01,//ReportSize(1)
0x95,0x04,//ReportCount(4)
0x15,0x00,//LogicalMinimum(0)
0x25,0x01,//LogicalMaximum(1)
0x81,0x02,//Input(Data,Var,Abs,NoWrap,Linear,PreferredState,NoNullPosition)
0x75,0x04,//ReportSize(4)
0x95,0x01,//ReportCount(1)
0x81,0x03,//Input(Const,Var,Abs,NoWrap,Linear,PreferredState,NoNullPosition)
0xC0,//EndCollection0x05,0x41,//UsagePage(Braille)
0x09,0x02,//USAGE(BrailleRow)
0xA1,0x02,//Collection(Logical)
0x09,0x02,//Usage(8DotBrailleCell)
0x15,0x00,//LogicalMinimum(0)
0x26,0xFF,0x00,//LogicalMaximum(255)
0x75,0x08,//ReportSize(8)
0x95,0x14,//ReportCount(20)
0x91,0x03,//Output(Const,Var,Abs,NoWrap,Linear,PreferredState,NoNullPosition,Non‐volatile)
0x09,0xFA,//USAGE(RouterSet1)
0xA1,0x02,//Collection(Logical)
0x0A,0x00,0x01,//Usage(RouterKey)
0x15,0x00,//LogicalMinimum(0)
0x25,0x01,//LogicalMaximum(1)
0x75,0x01,//ReportSize(1)
0x95,0x14,//ReportCount(20)
0x81,0x02,//Input(Data,Var,Abs,NoWrap,Linear,PreferredState,NoNullPosition)
0x75,0x04,//ReportSize(4)
0x95,0x01,//ReportCount(1)
0x81,0x03,//Input(Const,Var,Abs,NoWrap,Linear,PreferredState,NoNullPosition) 
0xC0,//EndCollection
0xC0,//EndCollection
0xC0,//EndCollection
};

BrailleDisplay_::BrailleDisplay_(void) 
{
	static HIDSubDescriptor node(_hidMultiReportDescriptorConsumer, sizeof(_hidMultiReportDescriptorConsumer));
	HID().AppendDescriptor(&node);
}

void BrailleDisplay_::begin()
{

}


void BrailleDisplay_::SendReport(void* data, int length)
{
	HID().SendReport(HID_REPORTID_CONSUMERCONTROL, data, length);
}

BrailleDisplay_ BrailleDisplay;
