/* ---------------------------------------------------------------------------------------------- */
/* MHash-384 - Self-test code                                                                     */
/* Copyright(c) 2016-2018 LoRd_MuldeR <mulder2@gmx.de>                                            */
/*                                                                                                */
/* Permission is hereby granted, free of charge, to any person obtaining a copy of this software  */
/* and associated documentation files (the "Software"), to deal in the Software without           */
/* restriction, including without limitation the rights to use, copy, modify, merge, publish,     */
/* distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the  */
/* Software is furnished to do so, subject to the following conditions:                           */
/*                                                                                                */
/* The above copyright notice and this permission notice shall be included in all copies or       */
/* substantial portions of the Software.                                                          */
/*                                                                                                */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING  */
/* BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND     */
/* NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   */
/* DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, */
/* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.        */
/* ---------------------------------------------------------------------------------------------- */

#ifndef MHASH_CLI_SELFTEST_INCLUDED
#define MHASH_CLI_SELFTEST_INCLUDED

/*Include*/
#include "mhash_384.h"
#include "utilities.h"

/*CRT includes*/
#include <stdlib.h>
#include <stdio.h>

/*C++ support*/
#ifdef __cplusplus
using namespace mhash_384;
using namespace mhash_384::internals;
#endif

/*Abort helper macro*/
#ifndef NDEBUG
#define ABORT_TEST(X) abort()
#else
#define ABORT_TEST(X) exit((X))
#endif

/*Assert macro*/
#define MY_ASSERT(EXP, MSG) do \
{ \
	if(!(EXP)) \
	{ \
		fprintf(stderr, "FAILURE: %s!\n\n", (MSG)); \
		for(;;) ABORT_TEST(1); \
	} \
} \
while(0)

/*Test vectors and reference outputs (short)*/
static const struct
{
	uint_fast32_t itrations;
	uint_fast32_t len;
	const char *const str;
}
TEST_VECTOR[] =
{
	{ 0x0000001, 0x000, "" },
	{ 0x0000001, 0x000, "abc" },
	{ 0x0000001, 0x000, "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq" },
	{ 0x0000001, 0x000, "abcdefghbcdefghicdefghijdefghijkefghijklfghijklmghijklmnhijklmnoijklmnopjklmnopqklmnopqrlmnopqrsmnopqrstnopqrstu" },
	{ 0x0000001, 0x000, "Franz jagt im komplett verwahrlosten Taxi quer durch Bayern" },
	{ 0x0000001, 0x000, "Frank jagt im komplett verwahrlosten Taxi quer durch Bayern" },
	{ 0x0000001, 0x000, "Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet.\nDuis autem vel eum iriure dolor in hendrerit in vulputate velit esse molestie consequat, vel illum dolore eu feugiat nulla facilisis at vero eros et accumsan et iusto odio dignissim qui blandit praesent luptatum zzril delenit augue duis dolore te feugait nulla facilisi. Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat.\nUt wisi enim ad minim veniam, quis nostrud exerci tation ullamcorper suscipit lobortis nisl ut aliquip ex ea commodo consequat. Duis autem vel eum iriure dolor in hendrerit in vulputate velit esse molestie consequat, vel illum dolore eu feugiat nulla facilisis at vero eros et accumsan et iusto odio dignissim qui blandit praesent luptatum zzril delenit augue duis dolore te feugait nulla facilisi.\nNam liber tempor cum soluta nobis eleifend option congue nihil imperdiet doming id quod mazim placerat facer possim assum. Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat. Ut wisi enim ad minim veniam, quis nostrud exerci tation ullamcorper suscipit lobortis nisl ut aliquip ex ea commodo consequat.\nDuis autem vel eum iriure dolor in hendrerit in vulputate velit esse molestie consequat, vel illum dolore eu feugiat nulla facilisis.\nAt vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, At accusam aliquyam diam diam dolore dolores duo eirmod eos erat, et nonumy sed tempor et et invidunt justo labore Stet clita ea et gubergren, kasd magna no rebum. sanctus sea sed takimata ut vero voluptua. est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat.\nConsetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus.\nLorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet.\nDuis autem vel eum iriure dolor in hendrerit in vulputate velit esse molestie consequat, vel illum dolore eu feugiat nulla facilisis at vero eros et accumsan et iusto odio dignissim qui blandit praesent luptatum zzril delenit augue duis dolore te feugait nulla facilisi. Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat.\nUt wisi enim ad minim veniam, quis nostrud exerci tation ullamcorper suscipit lobortis nisl ut aliquip ex ea commodo consequat. Duis autem vel eum iriure dolor in hendrerit in vulputate velit esse molestie consequat, vel illum dolore eu feugiat nulla facilisis at vero eros et accumsan et iusto odio dignissim qui blandit praesent luptatum zzril delenit augue duis dolore te feugait nulla facilisi.\nNam liber tempor cum soluta nobis eleifend option congue nihil imperdiet doming id quod mazim placerat facer possim assum. Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat. Ut wisi enim ad minim veniam, quis nostrud exerci tation ullamcorper suscipit lobortis nisl ut aliquip ex ea commodo." },
	{ 0x0000001, 0x200, "\x92\xAD\xAC\x49\x7F\xFA\xB3\x0B\x40\xAC\x67\x4F\x9D\x53\xA9\xA6\x24\xB2\x47\xFA\x23\x72\x94\xFA\x75\x88\x41\xA8\x5F\x4D\xDE\xFD\xDB\xFD\x23\x71\xC1\xE2\xCA\xF8\x5B\x0E\x06\x4B\xBC\x4F\x3A\xC0\xA9\xC6\xFD\x6C\x18\x5D\xC4\xB1\x2C\x8A\xAC\xC3\xE6\x25\xBD\xE8\x7A\xDF\xCB\xFF\x60\x1B\xF0\x66\xDF\x08\x7C\x0A\x63\xCE\x2C\x11\xD6\x64\x8D\x1E\xD0\x57\xCE\x1B\x5D\x93\xC6\xCB\x6F\x33\x19\x81\xB9\xFC\xB5\xBC\xF4\xFB\x6F\x77\x50\x54\x06\xD7\x1A\x87\xEC\x7E\xC1\x99\x55\x97\xFB\xB7\x96\x9D\xEC\x0D\xAD\x01\x93\x9E\x88\x89\xF5\x30\x96\x3F\xE9\x2E\x23\xA8\xF5\xDA\xE5\x47\x3E\x2C\x1E\x22\x38\x2A\xD4\xF7\x0E\xA2\xE4\x5E\xBB\xCB\xAD\x11\xC8\x7A\x74\x8F\x78\xCB\x56\x77\x8E\xF4\x1C\x0A\xEC\xA5\x63\x2E\x75\xE3\x52\xB2\xEA\xB5\x53\x3C\x06\xF7\xC6\x80\x8E\x77\xD0\x0B\x2D\xB5\xF9\x64\xF5\x9F\x89\x83\xD9\x25\x79\x22\x26\xE2\xF3\xE6\xD4\xB0\xFD\xE7\xBA\x74\x6C\x59\xBA\x9A\x20\x21\x2C\x25\xDA\x02\xD2\x3A\xEE\x5F\x88\x5A\x75\xF1\x1A\xC5\xBD\xD5\xCC\x6F\x9C\x4B\x72\xBC\x47\xD8\x40\x89\x72\x00\xF1\xB7\xEF\x97\x7F\x23\x52\x2C\x83\x38\xA3\xFC\xFD\xD7\x72\xC6\x15\xD3\x4A\x93\x46\xBC\xB1\xCE\x37\x14\xFC\x0E\x2B\xCB\x99\xC7\x34\x4D\xAC\xD8\x48\xA1\xEE\x58\x43\x6D\xB4\x78\xD0\x30\xE4\x09\xF1\x7B\x3A\xE9\x60\x68\xD9\x06\xF8\x59\x22\x6A\x66\x47\xD6\x09\x8A\x95\x18\x3B\x01\x46\x0D\x29\x36\x7B\xA5\x22\xB4\x05\x7E\x30\xAC\x8B\xC2\xD5\x4C\xBB\x63\x50\x0B\x76\xA1\x36\xEB\x36\xA0\x77\xD8\xF7\x98\x14\x57\x91\x0E\x8D\x9C\x42\x95\xE9\x39\x42\x01\xC9\xB8\xDF\x82\x87\xFF\xE5\xE6\x66\x80\x0B\x19\xB4\x13\xAC\xEC\x71\x2A\x5D\x35\xC5\xCA\x0F\x56\xE6\xA3\x51\x70\x58\x21\xB2\x20\x8D\xC9\xDE\xCC\x25\x19\xD5\xCF\xA1\xB9\x2B\x68\xBE\xD2\x64\x32\x94\x9B\x02\x7C\xF2\x00\xFE\x3D\x8B\x40\xA2\x19\x50\x0F\xEE\x41\x61\x23\xA8\xC5\xA3\xF5\xFC\x37\x35\x1E\x6A\x51\x42\xAA\x33\x8D\x34\x11\xF8\xB3\xBD\x2B\x74\x99\x16\xFF\xAD\x26\x8F\x00\xC5\xF5\x1C\x59\x22\x02\x3E\xB1\x71\x08\x43\xBF\xA7\x6B\xCD\x03\x33\x0E\x53\x9D\xBA\xE5\x28\xCA\x09\xE6\x1B\xAE\x11\x76\xA9\x7A\x89\xDF\x48\xDC\x85\xF1\x9A\xED\x9F\xE1\x9F\x2D\xB7\xDA\x21\xBA\xD1\x0C\xCA\x67\x05\x5B\xCC\x24\x5B\xEA\xF0\xB8\x6C\xC4\xB8" },
	{ 0x0000001, 0x400, "\x05\x85\x7B\xAA\xC0\xC9\xE8\x62\x60\x62\xB0\xA0\x22\x03\x88\xA6\x84\x43\xAA\x8C\x77\x0C\x82\x94\x5D\x35\x82\x98\x04\x1C\xDD\xA8\xD4\x4E\x90\x6F\x6D\xB9\x81\xE2\x7B\x3F\x95\x74\x24\x3E\x9F\x53\x7B\xEF\x0A\x25\x47\x79\x89\x5C\xB6\xB2\x37\xFC\x4F\x74\x6F\x7F\xCD\xE3\x73\x8B\xF5\xD1\xA2\x3C\xBC\x70\xF1\x41\x84\xF2\xEB\x37\x9B\xCB\xC3\xD7\x46\x2E\x52\xC3\x97\x3A\xB6\x74\xF3\xD5\xBB\x5A\x89\x36\xF3\x1D\xD5\xA1\x0E\xF1\x8E\xF4\x17\x26\xCE\x66\x00\x28\xDE\x17\x3D\x5B\x3B\x83\x7B\xD3\xAB\xC4\xA1\xEF\x8A\x59\xA2\xE2\xBA\x6E\x13\xEE\xEA\x83\x6B\xC1\xB1\x17\x9C\x65\x1A\xBE\x45\xA7\xB2\x40\x91\x99\x07\x9F\x4B\x5F\xBE\xF8\xC6\x7E\x4E\x0A\xFF\x5B\xB5\x5A\x7C\x2F\x9E\x77\xEE\x3B\xE0\xB5\x62\x80\x22\x9D\x2D\x13\xCB\xBC\x33\x80\xDD\xAB\x15\xAA\xAD\x04\x3A\xAD\x8C\xD5\x32\x4D\x30\x32\xF0\x71\x47\x27\x5E\x4B\x12\xFB\xEF\x7B\xAB\x83\xAC\x9D\xCD\xED\xEE\x2C\x25\x69\x19\x6D\x60\xEF\x18\xB5\xA0\x80\x9D\xA2\x83\x31\x87\x07\x53\x52\xE1\x5B\x4C\x1E\xFF\x41\x61\x34\x1C\x3E\x1F\x5F\xA2\x58\xD7\x67\x56\x23\xB6\xEC\xF5\xBC\x27\xCE\xCD\xB4\xB2\x57\xB1\x3B\xEB\xA6\x58\x95\xE0\xB5\xE8\xB1\x9E\x18\x3F\x4B\x60\x96\x4E\xFB\x59\x25\x06\xF4\x95\x83\x80\x98\x5D\x9F\x59\x9B\x83\x26\x97\x89\xCE\xAC\xBB\xD0\x5C\x95\x37\xDC\xE4\xDD\x2F\x5C\x22\x9C\x65\x10\xFB\x61\xA1\x73\xA1\x6A\x89\x61\x93\x7C\xC8\x6E\x80\xB8\x48\x57\x48\x4F\x88\x7E\x6A\xCE\x90\xF3\xEB\xB3\x9F\x50\xF0\x0F\xB6\x29\x60\x28\xE5\x8B\xDF\xEA\xCA\xFB\x3C\xDD\xAA\x60\x60\x73\xB3\xAE\x45\x4F\xC9\x1D\xB2\x63\x31\x30\x3B\x85\xBA\x8A\x37\x41\xD6\x5A\x52\x11\xA2\x2A\x11\x39\xD2\x1E\x2D\xBF\x1A\x53\x8A\x13\x24\xC7\xA3\xDE\xBE\x0B\x23\x72\xCC\x92\x29\xB8\x2B\x92\x8F\x08\x0A\xB4\xA6\x47\x76\x29\x39\xBF\x40\xBC\x59\x9F\xCD\x9D\xCF\x35\x51\x16\xF5\x44\x40\xA4\xC3\x1D\xA8\x8C\x73\xC0\xA1\x12\x84\x15\x4D\xB1\x7B\x4A\x44\xF4\x12\x8E\x0F\xE4\x4C\x7E\x5C\xB2\x92\x5F\xA9\xB3\x71\xDA\x40\x50\x78\xC7\x02\x1F\x20\x79\x84\xF3\x91\x1F\x47\x47\x40\x67\x2B\x52\xA1\x67\x91\x05\xCA\xB4\xAB\xA8\x69\x40\xFD\x7F\x28\xF6\x17\xB0\xDD\x1A\x82\x0F\x20\x5D\xD2\x39\xA8\x9A\x73\xF1\xAC\x10\x18\x3C\x69\x99\x49\xB8\xB2\x90\x24\xB5\x2E\x0C\x57\x93\x6A\x1B\x0B\x9C\xB9\xF5\x45\x71\xDD\xAF\x94\x6F\xA5\xF5\xCF\xB1\xBC\x1C\x0E\x5E\x5A\x0E\xF6\x9D\x9E\x71\x11\x99\x9F\xA4\x57\xE6\x6D\xD5\x83\x00\xD7\x85\x0C\x54\x01\xD4\x49\x1C\xF6\x8C\x8E\x00\x8B\xF8\x48\x50\x4D\x6F\xF1\xEA\xEF\x2D\x64\xD4\xF5\x00\xA9\x03\xE6\xCB\x5F\xCF\x6C\xD6\x26\xC1\xF4\x97\xCF\xB5\x16\xA1\x62\xDE\xFF\xC2\x00\xD0\x9A\x5E\xBB\xB4\x76\x86\xFD\x4B\xF2\x29\x4F\x0F\x69\x15\x7D\xAC\xAA\x2B\xD1\xBA\x6E\xA2\x1A\xC1\x6B\x9A\x14\x90\x63\xBD\xC4\x31\x36\xBB\x26\xA7\x69\x7D\x11\x76\xE5\x3F\x05\xC5\x4F\x6D\xB0\x12\x2E\xBC\x72\x18\x8A\x0F\x07\xA1\x2A\xD0\xC0\xDE\x2B\x63\x19\x6E\xA8\x7F\xC7\x9D\x47\x2F\xA6\x62\xA3\x57\xF0\x37\x58\x9F\x80\x4D\x9D\xA9\x2F\x2A\x39\x79\x16\x6A\xCA\xDF\x22\x8F\x2F\xAA\xA2\x72\x75\x96\x63\x19\xE2\xDF\x7E\x37\x1D\x68\xF8\xD9\x5D\x8D\x40\x23\x7F\xF5\x1B\x40\x33\xCB\x38\x81\x4F\x4A\x5E\x25\x3C\xF0\x19\xD7\x01\xD1\x21\xF6\xC5\x6F\xDA\x17\x83\x60\x39\x25\x66\xF2\x25\x31\x58\xA6\xA4\xAD\x46\x78\xE7\x76\x57\x19\xCB\x7C\x9C\x6D\xE0\x6D\xF8\xFD\x28\x14\x14\x0D\xF0\x0C\x8F\xD4\x68\x59\xD2\x96\x15\xBF\xEC\x8A\x34\xF7\x1A\x3B\x2C\x8C\x4A\x98\x16\x37\x7D\x95\x15\xBD\x45\xCB\xF8\xC1\xA1\x9E\x64\x3A\x17\x4C\xC4\xD2\xD1\xA0\xA4\xBD\x5A\x79\xCB\x53\xBC\x37\x84\xC8\x4F\x9B\xD7\x10\x42\x3D\x26\x40\xD6\xF2\x50\x20\x17\x8C\x2A\x81\x3A\xB5\xD2\x8B\x66\xE5\x9F\xCB\xEB\x29\xC8\x41\xD1\xB1\x9F\xBA\x77\x2A\x18\xD7\x7F\x8D\x46\x60\xFE\xDB\xE4\xC1\xA5\x73\xDD\x88\x7B\x17\xAA\x3D\x58\x30\x9B\xF6\xB2\x66\x4E\xAC\xC3\xE3\xA4\x7A\xAE\xDF\x33\xBE\x52\x89\xB7\xF9\xB0\x18\xFB\x70\x63\x9A\xC2\xB5\xFD\xEF\x3C\x8E\x91\x69\x5F\xA8\xE0\xF6\x83\x25\xEF\x16\xAA\xAF\x27\xB5\xD5\x2C\x58\x57\x35\x67\x5D\x11\x31\xA3\x25\x39\x0D\x5C\xF1\xAC\xD4\xFB\x03\x4C\x8A\xC0\xFB\xB2\xE5\x0E\xAD\x7F\xC9\xB1\x33\xAE\xD9\xEE\x3D\x71\xCB\x23\x54\xF9\x7F\xBF\x02\x4D\xE1\xD2\xBC\x66\xA9\x5C\x9D\x36\x47\x5A\x62\x76\xEF\xC5\xC8\x30\xBC\x78\x79\x92\x62\xA8\xE9\x0B\x83\xE5\x91\x42\x8F\xFC\xE9\xA8\x6C\xAB\xA9\x75\xA1\x9B\x6B\xA2\xE5\x87\x96\xBE\x16\x84\x0A\x04\x29\x9F\x2E\x2D\xC9\xC8\xDA\xEA\xF6\x9A\x25\x0F\xF8\xC0\xFD\xB5\xD7\x82" },
	{ 0x0000001, 0x600, "\xFF\xD3\xB0\xA7\x2D\x6F\x68\x3A\x0B\x80\x75\xAA\xE0\xE7\x1E\x77\x32\x81\x7D\x74\x65\xEE\x85\xB5\x7A\xD8\xD6\x53\xCE\x9F\x4F\xB7\xBD\xD4\xB0\xB6\x7B\x44\xA5\x2C\x2E\x69\xC9\x60\xE3\xAE\xC7\xAD\x66\x04\xDC\x1D\xB1\xAE\xB2\xAE\x5E\xF0\x78\xCB\x08\xFF\x40\x1C\x36\x34\x0C\x10\xE3\x41\x9B\x80\x8F\x62\xBF\xD6\x25\xB7\x2D\x74\x83\x4F\x24\x7E\xBA\xB7\x0D\x87\x9A\x5C\x72\xE6\xF0\x09\x79\x51\x2B\x1F\xE6\x4A\xC0\x22\x17\x58\x66\xE9\x8B\xB2\x92\xE3\x62\xFC\x73\x6E\xBC\x72\xD5\xCF\x08\x05\x4B\xB6\x14\x3C\x91\x33\x3E\x60\xBA\x81\xC3\xFD\x32\xA9\xB7\x64\xD8\x1F\x9B\x44\x63\x2D\x1A\x70\xE1\xF5\x4E\xA0\x8D\x3C\x20\x8C\x46\x59\xF5\xF4\xE2\xE6\xA2\xA7\xE8\x18\xCB\x4D\xDB\x5A\xC6\x90\x93\xAC\xDF\x6A\xFF\xD1\x00\x96\x4F\xFC\xEF\xB7\x6A\xEB\xBB\x87\x30\x4F\xFC\x19\xCE\x12\x33\xC1\x13\xDE\xDF\xA3\x7B\x89\xC2\xA3\xDC\xA4\xA9\xBD\x04\x10\x96\xEE\xB8\x77\xFA\x98\x5C\x42\x01\xF3\xF5\xD4\xEF\x18\x0E\xB4\x0F\x2E\x2C\xFC\x9A\xD0\xCF\x4C\x99\xE1\x20\xF0\x65\x5B\xFE\xAF\xF0\x9B\xB5\xDF\xD5\x2B\xC2\x3D\xB0\xFD\xE8\x31\x3C\x7F\xA6\x65\x6F\xBA\x0E\xD9\xC9\x8D\x5B\xD1\xEA\x7C\x7F\x4B\x52\xED\x80\x4F\x26\x17\x95\x91\x6B\xB8\x08\x2C\x1E\x62\x4F\xD2\xD0\x7A\x00\x75\xA6\x13\x29\x93\xCB\xC4\xC5\xA7\x9E\x90\xB1\x7C\x8C\x1C\x7A\x59\x6C\x1D\x5D\xFC\x46\xAF\x0C\x96\xBA\x31\x95\x44\x7B\xCB\x5E\xAB\x64\x42\xF7\x35\x7A\x1F\x87\xF2\xB3\x3E\x42\x33\x28\xCF\x52\x47\x47\x13\x9A\xA3\x63\xD1\xBD\x7A\xF0\x0C\x90\x68\x1D\x0C\x03\x83\xA9\x8E\x9D\x7A\x5C\x6A\x1E\x66\xA9\xF1\x2B\xB8\xCE\xA2\xD2\x2B\x17\x21\xB1\x83\x87\xFC\xF1\xF3\x46\x78\xDC\xD3\x96\x66\xC2\xB4\xD3\x83\x02\xA8\xD7\xA5\x95\xDF\x30\x04\xF2\xD1\x52\x8C\x5A\x44\x62\x68\xBC\xCD\xA7\x69\xCB\x4E\xB4\x5B\x10\x83\x59\xAC\x28\x29\x13\x04\xC3\xB2\x7A\xC5\x35\xA7\xB0\x0A\xD4\xF0\xF0\xEC\xB4\xC0\xF2\xD2\xC2\x2B\x88\x03\xD5\xE6\x4E\x6F\xEF\xAD\x7D\xD8\x0F\xF0\x6C\xB0\xB1\x09\xD8\x9D\x99\x14\xE3\x00\x05\x23\xC7\x15\xB9\xB1\xB7\xF1\xEE\x9F\xCE\x04\x39\xB7\xE2\x4D\x0C\x5A\x13\x7A\x72\x08\x21\x11\x28\xB2\x35\xEC\x7A\xE5\x23\xD5\x66\xD6\x4C\x7A\x82\xFD\x6E\x1F\x3A\x01\xDC\x38\x3A\x21\x7B\x23\xB5\xFA\xCC\x05\x65\x8D\xDC\xDA\x5C\xA7\x0A\x1A\xA0\x02\xF4\xB6\xA0\x32\x34\x77\xC5\xE2\xBB\x10\x46\xCE\x57\xE3\xA9\x0B\x65\x73\x8F\xD5\xA5\x17\x83\x00\xBD\x40\xB1\xEE\x44\xF4\xEB\x28\x5B\x96\xA6\xC1\x94\xD3\xB6\x4B\xAE\xF4\x72\xF6\xEC\xAC\xD4\x52\x9E\xC7\x7A\xA8\x4B\x3D\x1D\xBC\xC0\x57\x7B\x91\x62\xEE\x4D\x67\xF3\xBA\x8D\xBB\x6D\xE7\x48\x5E\xBE\x16\x48\x85\x6C\x52\x48\x00\xFF\x06\x95\xE1\x7E\xD9\x13\x98\xE0\x6D\x96\x13\xB7\x4B\x28\x3B\xAC\xC5\x0A\x37\x85\xBB\x6E\xE5\xE9\x2F\x2C\x0E\x9E\xB7\x44\xE7\x85\xF2\x5B\xFD\xEE\x8B\xC2\xB8\x30\xE0\x81\x29\x94\xDB\x33\xFF\x88\x32\x91\xF9\xCB\x14\xBC\x2D\x91\x26\x13\x4A\xA2\xE2\xD7\xD0\xCA\x9F\x1F\x36\x7A\x12\x7D\x0C\x9A\x0B\xE6\x5C\xE2\xB7\x4D\xE5\x0B\xA4\x3E\x25\xF8\xD9\x8D\x9D\xF4\xE3\x2C\x8A\x9B\x98\xAD\x6B\xF5\x0F\xFB\x7D\xDA\x2A\xFE\x21\x18\x76\x9A\x1A\x55\xFC\x25\xCA\x3E\xF9\xFD\xE4\xB6\x2D\x10\x3E\x58\x79\xD8\x30\xED\xDD\x4B\xB6\x0F\xD5\xD6\xF6\xB4\xB1\x37\x7C\x4E\x29\xE6\xF7\x79\x23\x74\x01\x66\x5F\x02\xEB\xF2\x9F\x51\x02\x39\x31\xAA\x8B\xBC\xDE\x6E\x5A\x6D\xAF\x3A\x84\x23\x34\xF4\x13\x9C\x04\xFD\x7E\x6C\xE7\x22\xCC\xB9\x32\x6B\xD9\xC2\x77\xC2\x7B\xDF\xE9\xB6\x17\x53\xAF\x7B\xA6\x94\xAE\x39\x39\x00\xEF\x75\xE2\x4D\x15\xF6\x45\x1A\xB2\x9F\xD6\x82\x24\x45\xB2\x07\xA7\x00\x3D\x14\x01\x62\x40\xDD\xD2\xB8\xF0\x96\x9B\x07\x0C\x49\xF8\x74\xB2\xBF\xE9\x31\xB3\x2E\x9D\x2F\x30\xC2\xF6\xED\x4C\x56\x42\xD4\x47\x55\x6A\xF4\x39\xC2\x23\x5F\x58\xBD\x2C\x7B\xC5\x4A\xDC\x8A\xAD\x40\xE5\x84\xA0\x65\xB3\x65\x73\x74\x9F\xAB\xBD\xE6\x09\xA2\x24\x65\x8D\xF6\x5B\x5B\x14\x4B\xC0\x6A\x78\xF2\xD6\xF3\x76\x45\xA0\x77\xDD\xAA\xDB\x13\xF9\x9F\x0F\x5A\xA5\xA0\xB9\x28\x48\x95\x24\x03\x2D\x94\x6E\xE1\x05\xF7\x5C\x23\x82\x29\x95\xA1\x7C\xF2\xE3\xB9\x2F\xAC\x29\x11\xEC\x60\xD1\x4C\x5F\xB8\xD2\x1E\x9D\xEC\x76\x1D\xFC\x5F\xC0\xFE\xD1\x50\x33\x0A\x42\xD7\x83\xC9\xF9\x49\x54\xBB\x50\x17\x6C\x6B\x38\xC1\x31\x19\xDB\xFC\xDE\xCE\x17\xAD\xB2\xD1\xDA\x0A\x13\xEE\x2B\xED\x3A\xEA\xEA\x20\x8E\x17\x14\x0B\x88\xEE\xB9\xA5\x02\x1B\xE8\x6C\xF7\xFB\xE4\x18\x72\xE7\x35\x88\xDE\x8E\xB8\x56\xFB\xD9\x8C\xB8\x81\xA7\x39\xAC\xF2\xD2\x39\x0B\xAF\x7F\xB6\xD2\x0E\xA5\xC7\xA0\xB3\xEF\x6F\x4B\xF4\x08\x78\xB2\xA8\x89\xCD\x0E\x0E\x8A\xB1\x8F\x8C\xAC\xE3\x23\x23\xB6\xD1\x6C\x80\xFD\xF5\x4D\x65\x3B\x75\x17\xFC\x81\xA3\x88\x15\x2A\xEE\x19\xE0\xFD\xF5\xF1\xC2\xC3\xDD\xEE\x7A\x08\x12\x25\x72\x75\x42\x77\x8D\x51\x5B\xD6\x31\x61\x88\x21\x73\x86\x2E\xE5\x8E\x0B\x3E\xBE\x61\xB8\xE4\xFD\xFA\x67\xC6\x44\x78\xB2\x31\xD9\x8B\xBF\xA8\x07\x8F\x7E\xBE\x46\x54\x53\x24\x9A\x25\xE5\xD3\x5F\xC0\x22\x20\xEA\xC0\x86\xCD\x6C\xF8\x7A\x4A\x6C\x18\xBD\x0F\xCC\xF3\x5F\x7F\xE0\xBE\xB0\x53\x94\x5F\xE0\x89\x11\x86\x92\xF2\x3F\x1A\xBD\xE8\x68\xB8\x35\x3B\x91\x8F\x85\x73\x98\xB9\x7E\xD1\xC0\xAD\xF8\x4D\x72\x04\x4F\x1D\xAD\x82\x5F\x86\xDD\x89\x17\x73\x38\xF8\x25\x34\xBA\x57\x24\xF8\xF3\xE3\x50\xAE\x41\xD9\x91\xF8\xAC\x8E\xC4\x87\xF6\x58\xD2\x1C\x31\x9B\xC9\x0E\x28\x56\xC9\x5F\x09\x43\x73\xA0\x79\x13\x58\xF2\x5E\x25\x89\x8F\x17\x58\x9E\xB3\x5E\x30\x6C\x8A\xAB\x81\x43\x27\x6C\x53\x82\x08\x19\xB9\xC0\xFB\xDA\xF4\xDD\xBD\x55\x66\x8D\x71\xFF\x67\x40\x4E\x53\xB3\x70\x22\x7B\x80\x20\x8C\x92\x3F\x0F\x73\xAB\xF1\xE4\x5A\xA2\x57\x3D\xDF\xDE\x39\xD0\xE5\x47\x1C\x41\xDA\x7A\x95\x0C\x5E\xE4\xA3\x84\x34\x6E\x3E\xA4\x9A\xFD\x22\x46\xA9\x79\x65\x69\x19\x6A\xCE\x8A\xE9\x58\x94\x4A\xE1\xD9\x71\x02\xD9\x8F\x46\xA6\x5C\x59\x48\x1F\x63\x97\x1F\xAF\xFC\x11\xF0\x08\x02\x11\x02\xFF\x70\xA4\xE7\x3A\xB9\x5C\xF1\x70\xCA\x58\xF3\x1A\x00\x14\xFA\x7C\xBF\x7E\x1B\xDE\x7E\xD6\x4F\x58\x40\xFB\x8F\xEA\xDC\x8B\xEC\xE2\x2A\xDD\x39\x97\x04\xBE\x3D\x8E\x0C\xAD\x9B\x48\xEF\x92\x5F\x76\xE3\x0C\x0D\x40\x20\x08\x4A\x46\xE7\x65\x38\xF1\xB4\x43\xE6\x99\x06\x5D\xD5\x4D\x7B\xDF\xD6\x46\x7A\x92\x55\x56\x08\xE4\x5F\x08\xD8\xC5\x94\xA6\x5E\xFE\x3B\xEC\xA3\xE8\x54\x90\x2B\xF7\xF3\x37\x25\x90\x26\x0A\x1C\x78\xE6\xE5\x8D\xFF\x53\x96\x4B\xBB\xE4\xDE\x46\x05\x68\x7C\xBF\x05\x19\xD4\xD2\xC6\x8E\xAE\xE9\x45\x31\x60\xF8\x4C\xD1\x9A\xF1\xCA\x6E\x6E\x61\x33\xD0\x57\x15\x0E\x15\x6A\x14\x06\x1D\xCE\x65\xCA\x45\x71\xA7\xBB\x7A\xDE\xCE\xF6\xEA\x62\xA6\xFA\x54\xC1\xAE\xB4\x77\x26\x07\xC0\x10\x30\xB1\xCC\x24\xBF\xE8\x45\xC2\xA9\xD3\x4B\x66\xA1\xE3\xF0\x57\xB0\xFE" },
	{ 0x0000001, 0x000, "fatherblessedthemallwithreasonandthisiswhattheychooseandthisiswhattheychoose" },
	{ 0x0000001, 0x000, "inerw\xC3\xA4gungdassdah\xC3\xA4userstehenw\xC3\xA4" "hrendihrunsohnebleibelassthabenwirbeschlossenjetztdorteinzuziehenweilesunsinunsernl\xC3\xB6" "chernnichtmehrpasst" },
	{ 0x0000001, 0x000, "hewasborninacoopraisedinacagechildrenfearhimcriticsrageheshalfaliveheshalfdeadHESGOTABUCKETONHISHEAD!" },
	{ 0x000002A, 0x000, "(~2GS:=%/R&En0Z2@eY^a9WMifNUdx]?)6j8}En7R8{n7-aYXV99g|r(SU5]+wOvuq9A)]x|kTr*\\mm;skW:aZ}89B`c$3>aHtli9_VeFo_%dr,Hi\"kkD8O_Tra3L2/W>sO>5P6f{dJv+w}S=HW4>>E|JNU&$[W4**IxMEbIvzD%qfj+h^_v-b2DA`z!Hvs@,YN!M>t+;Q2z_<6C4S<T6Koqb](YCm6?{]QuEJ_;}{1:/E$5+Ss1]T>,,hoF=zT`" },
	{ 0x0000001, 0x000, "3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196442881097566593344612847564823378678316527120190914564856692346034861045432664821339360726024914127372458700660631558817488152092096282925409171536436789259036001133053054882046652138414695194151160943305727036575959195309218611738193261179310511854807446237996274956735188575272489122793818301194912983367336244065664308602139494639522473719070217986094370277053921717629317675238467481846766940513200056812714526356082778577134275778960917363717872146844090122495343014654958537105079227968925892354201995611212902196086403441815981362977477130996051870721134999999837297804995105973173281609631859502445945534690830264252230825334468503526193118817101000313783875288658753320838142061717766914730359825349042875546873115956286388235378759375195778185778053217122680661300192787661119590921642019893809525720106548586328" },
	{ 0x1000000, 0x000, "abcdefghbcdefghicdefghijdefghijkefghijklfghijklmghijklmnhijklmno" },
	{ 0x0000000, 0x000, NULL }
};
static const uint8_t TEST_RESULT[][MY_HASH_LENGTH] =
{
	{ 0x7B, 0x5E, 0x40, 0xA3, 0x5D, 0x2A, 0x27, 0x21, 0x24, 0x93, 0x20, 0x27, 0xF0, 0x9F, 0x0B, 0x9F, 0x26, 0x71, 0xD9, 0xEF, 0xF4, 0xC7, 0xE6, 0xF9, 0x74, 0x66, 0xEA, 0x67, 0x31, 0x61, 0x7D, 0xFA, 0x9B, 0x8B, 0x00, 0x46, 0xCB, 0x8D, 0x6A, 0xA1, 0xE5, 0xAD, 0xF5, 0x20, 0xFC, 0xE3, 0x4C, 0x32 }, /*00*/
	{ 0x94, 0x16, 0x8F, 0x71, 0x27, 0xDD, 0xE6, 0x1D, 0xB6, 0x90, 0xAC, 0xC4, 0xDC, 0xFC, 0xBF, 0x35, 0xEA, 0xF7, 0x7A, 0x15, 0x1F, 0x8B, 0xBA, 0xEE, 0x4F, 0xC3, 0xF7, 0x04, 0x57, 0x3D, 0xFD, 0x0D, 0xFE, 0x9C, 0xD5, 0xC4, 0xC3, 0xE0, 0x22, 0x7A, 0xC6, 0x58, 0x2A, 0x51, 0xF2, 0xC4, 0xD8, 0x64 }, /*01*/
	{ 0x55, 0x05, 0xC0, 0x3B, 0xFF, 0x14, 0x2D, 0x7B, 0x47, 0x37, 0xFA, 0x7F, 0x36, 0x75, 0x0F, 0x8E, 0x09, 0x34, 0xA3, 0x65, 0xFE, 0xF6, 0x15, 0x92, 0xE3, 0xD3, 0xB0, 0xD3, 0x08, 0x86, 0x7D, 0xAA, 0x44, 0x64, 0xEB, 0x35, 0xEA, 0x27, 0x07, 0x7A, 0xBE, 0xAC, 0xBE, 0x79, 0xB6, 0x57, 0x15, 0x30 }, /*02*/
	{ 0x6E, 0x5B, 0x90, 0xD2, 0x56, 0x81, 0xB4, 0x54, 0x50, 0xE2, 0x1F, 0xC8, 0x62, 0x73, 0xEB, 0xAD, 0xB7, 0x91, 0x73, 0x58, 0x69, 0xCE, 0x6D, 0xEE, 0xAE, 0x1A, 0xD5, 0x27, 0x80, 0x5A, 0xAC, 0x62, 0xD8, 0x8E, 0xAE, 0xDD, 0x59, 0x2F, 0x20, 0x15, 0xFE, 0x80, 0x5F, 0x01, 0xF6, 0x32, 0x25, 0x32 }, /*03*/
	{ 0x1F, 0x41, 0x37, 0x2F, 0x44, 0xB6, 0x63, 0x4C, 0x7B, 0x63, 0xB6, 0xD8, 0x6B, 0xC2, 0xAF, 0x06, 0x83, 0x72, 0x78, 0xE6, 0x87, 0x21, 0x76, 0x73, 0x96, 0x49, 0xB0, 0x63, 0x0F, 0xD6, 0xBB, 0x72, 0xAD, 0xE6, 0x93, 0x38, 0x2A, 0x94, 0xB8, 0xC2, 0xF8, 0x74, 0xCF, 0x98, 0x5E, 0xCE, 0x41, 0xF2 }, /*04*/
	{ 0x3A, 0x2A, 0x83, 0x28, 0x0D, 0xB4, 0xE5, 0x95, 0xE0, 0x12, 0x11, 0x19, 0x32, 0xA7, 0x8D, 0x60, 0x8A, 0xE7, 0x9B, 0x2A, 0x01, 0xC8, 0x1D, 0xCB, 0xB4, 0xF6, 0x61, 0x43, 0x48, 0xD4, 0xBF, 0xD6, 0x98, 0x55, 0x40, 0xAF, 0xBC, 0xD8, 0x17, 0x13, 0xFF, 0x86, 0xCE, 0x8B, 0x5F, 0x5F, 0x8D, 0x02 }, /*05*/
	{ 0x21, 0xD1, 0xB5, 0xD8, 0xB8, 0x85, 0x30, 0xEC, 0xCB, 0x40, 0x39, 0x76, 0x08, 0x51, 0x37, 0x9D, 0x1E, 0x32, 0x04, 0xF8, 0x88, 0x9D, 0x9C, 0xC7, 0x3C, 0xE6, 0x23, 0x13, 0xF7, 0xD7, 0x37, 0x54, 0xDF, 0x98, 0xF3, 0xEE, 0xF2, 0x6E, 0xC5, 0x37, 0xD8, 0x41, 0x55, 0xB8, 0x91, 0x15, 0x22, 0x29 }, /*06*/
	{ 0xEC, 0x18, 0xE2, 0xAF, 0x4A, 0xC0, 0xD8, 0x62, 0x6A, 0xE5, 0x16, 0x59, 0x93, 0xDE, 0x29, 0xDB, 0xB2, 0x01, 0x30, 0xD1, 0xCE, 0x5B, 0x70, 0xA5, 0x52, 0xDA, 0xEC, 0xD7, 0x97, 0xE1, 0x5D, 0x9B, 0xB5, 0x41, 0x1B, 0x4A, 0x64, 0xC7, 0x8E, 0x1F, 0x0C, 0x6E, 0xEB, 0x56, 0x7A, 0x56, 0x0D, 0x85 }, /*07*/
	{ 0x11, 0x5C, 0x21, 0xBE, 0x85, 0xD7, 0x86, 0xD5, 0x39, 0x3B, 0x63, 0x5C, 0x3B, 0xB5, 0x35, 0x7A, 0x64, 0xCA, 0xDD, 0x58, 0x9A, 0xC8, 0x3F, 0x44, 0xF8, 0x51, 0x39, 0xD0, 0xA5, 0x72, 0xF0, 0xA1, 0xF6, 0xA9, 0x54, 0x47, 0x14, 0x12, 0xD9, 0x67, 0xF0, 0x9C, 0x5D, 0xEF, 0xC5, 0x00, 0x1A, 0xA2 }, /*08*/
	{ 0xB4, 0x65, 0xC4, 0xCA, 0x4E, 0x13, 0x93, 0x92, 0x1E, 0x51, 0xA6, 0xE4, 0x4F, 0x94, 0xBA, 0x5E, 0xF3, 0x41, 0xAA, 0x19, 0x57, 0x0B, 0xBD, 0x93, 0xDB, 0xDA, 0x66, 0xE5, 0x1E, 0x9A, 0xF0, 0x79, 0x50, 0x1B, 0xD6, 0x77, 0x17, 0x35, 0x44, 0xF4, 0xE6, 0x51, 0xBC, 0x75, 0xD3, 0x9E, 0x62, 0x27 }, /*09*/
	{ 0x3E, 0x9C, 0x8A, 0xAC, 0xE6, 0x82, 0xE2, 0xBC, 0xB3, 0x1A, 0xF7, 0x26, 0xF6, 0x18, 0x17, 0xDB, 0xDB, 0x1F, 0xBB, 0x61, 0xC8, 0x3D, 0x36, 0x94, 0x9E, 0xB8, 0xCF, 0xBF, 0x0F, 0x4C, 0xC8, 0x68, 0xD2, 0x0F, 0x43, 0x5C, 0x69, 0x26, 0xAA, 0xF8, 0xAB, 0x96, 0x2E, 0xBC, 0x7D, 0xDC, 0x02, 0x05 }, /*0A*/
	{ 0xAA, 0x7B, 0xC9, 0x28, 0x2A, 0xD0, 0x5D, 0xB2, 0x3D, 0x0C, 0x3C, 0xB5, 0xE7, 0x1E, 0xEF, 0x26, 0x2F, 0xD5, 0x9A, 0xEC, 0x23, 0x23, 0xF3, 0xA4, 0xB2, 0xAA, 0x52, 0xC9, 0xD3, 0xB1, 0x23, 0xD3, 0x5E, 0x1A, 0xD1, 0x20, 0x30, 0xE4, 0x4A, 0xCF, 0x7E, 0x53, 0x2F, 0x2D, 0xE9, 0x22, 0xD7, 0x8A }, /*0B*/
	{ 0x66, 0x67, 0xB6, 0x8B, 0x44, 0xB0, 0xE4, 0xB0, 0xC2, 0x34, 0xC9, 0x45, 0x08, 0x5E, 0x79, 0x24, 0x3F, 0xA0, 0x59, 0x20, 0x39, 0xE4, 0x77, 0xC2, 0xA2, 0x73, 0xA6, 0x76, 0x70, 0x3C, 0x6F, 0x3D, 0xF8, 0x51, 0xCD, 0x7C, 0xEB, 0x4F, 0x7F, 0x3B, 0x33, 0xD8, 0x94, 0x4C, 0x76, 0x3D, 0xC5, 0xAF }, /*0C*/
	{ 0xA1, 0xE3, 0xB0, 0xB2, 0x0B, 0x57, 0x32, 0xBD, 0xBC, 0x8B, 0xC7, 0x90, 0x7D, 0x58, 0x14, 0xA4, 0x4F, 0x76, 0xD0, 0xC2, 0x5D, 0x3A, 0x63, 0x4D, 0x12, 0x9F, 0x56, 0x18, 0xC4, 0xB7, 0x17, 0x4B, 0xC8, 0xFA, 0x20, 0x27, 0x85, 0x67, 0x78, 0xA8, 0x48, 0xB2, 0x79, 0x52, 0x5A, 0xD1, 0x0C, 0x00 }, /*0D*/
	{ 0x46, 0x73, 0xF5, 0x55, 0x3F, 0x56, 0xF0, 0x7E, 0x7C, 0x1D, 0xC1, 0x29, 0xD7, 0x95, 0x8E, 0xF2, 0xD2, 0xEF, 0x62, 0x6B, 0x5E, 0x26, 0x49, 0x1E, 0xDB, 0x64, 0xBE, 0xD9, 0xC2, 0xDF, 0x80, 0xFC, 0x2E, 0xAA, 0xA1, 0x2B, 0xA6, 0x27, 0xDA, 0x8C, 0xE2, 0x50, 0x39, 0x28, 0x1D, 0x04, 0xBE, 0xE3 }, /*0E*/
	{ 0x34, 0xD4, 0x0F, 0xD3, 0x95, 0x49, 0x87, 0x77, 0xC2, 0x0C, 0x7A, 0x8E, 0xA5, 0xEB, 0xED, 0x11, 0x5A, 0x1C, 0xB7, 0x7C, 0x74, 0x68, 0x98, 0x22, 0x9B, 0x96, 0x90, 0x6D, 0xA6, 0xB7, 0x39, 0xB6, 0x91, 0xC4, 0x73, 0x89, 0x7A, 0xFB, 0x80, 0x16, 0x40, 0xA5, 0x19, 0xE2, 0xA9, 0x03, 0xC3, 0xE0 }  /*0F*/
};

static MHASH_384_INLINE uint32_t test_distance_xor(const uint8_t *const a, const uint8_t *const b)
{
	uint_fast32_t k, distance = 0;
	for (k = 0; k < MY_HASH_LENGTH; k++)
	{
		uint8_t c = a[k] ^ b[k];
		while (c)
		{
			++distance;
			c &= (c - 1);
		}
	}
	return distance;
}

static MHASH_384_INLINE uint32_t test_distance_mix(const uint8_t *const a, const uint8_t *const b)
{
	uint_fast32_t k, distance = 0;
	for (k = 0; k < MY_HASH_LENGTH; ++k)
	{
		if (a[k] != b[k])
		{
			++distance;
		}
	}
	return distance;
}

static MHASH_384_INLINE uint32_t test_distance_sbx(const uint8_t ptr[][MY_HASH_LENGTH], const uint_fast16_t a, const uint_fast16_t b)
{
	uint_fast32_t k, distance = 0;
	for (k = 0; k < 256U; k++)
	{
		uint8_t c = ptr[k][a] ^ ptr[k][b];
		while (c)
		{
			++distance;
			c &= (c - 1);
		}
	}
	return distance;
}

static int self_test(void)
{
	uint_fast32_t i, j, k;
	uint8_t result[MY_HASH_LENGTH];
	mhash_384_t context;

	/*logo*/
	print_logo();

	/*test INI table*/
	fprintf(stderr, "Self-test, step 1 of 5 running...\n");
	for (i = 0U; i < 2U; i++)
	{
		for (j = 0U; j < 2U; j++)
		{
			const uint32_t distance = test_distance_xor(&MHASH_384_TABLE_INI[i][0], &MHASH_384_TABLE_INI[j][0]);
			if (i != j)
			{
				MY_ASSERT((distance == 192U), "INI table verification failed");
			}
			else
			{
				MY_ASSERT((distance == 0U), "INI table verification failed");
			}
		}
	}

	/*test XOR table*/
	fprintf(stderr, "Self-test, step 2 of 5 running...\n");
	for (i = 0U; i < 257U; i++)
	{
		for (j = 0U; j < 257U; j++)
		{
			const uint32_t distance = test_distance_xor(&MHASH_384_TABLE_XOR[i][0], &MHASH_384_TABLE_XOR[j][0]);
			if (i != j)
			{
				MY_ASSERT((distance >= 182U) && (distance <= 212U), "XOR table verification failed");
			}
			else
			{
				MY_ASSERT((distance == 0U), "XOR table verification failed");
			}
		}
	}

	/*test MIX table*/
	fprintf(stderr, "Self-test, step 3 of 5 running...\n");
	for (i = 0U; i < 256U; i++)
	{
		for (j = 0U; j < MY_HASH_LENGTH; j++)
		{
			int found = 0;
			for (k = 0U; k < MY_HASH_LENGTH; k++)
			{
				if (MHASH_384_TABLE_MIX[i][k] == (uint8_t)j)
				{
					MY_ASSERT((!found), "MIX table verification failed");
					found = 1;
				}
			}
			MY_ASSERT(found, "MIX table verification failed");
		}
	}
	for (i = 0U; i < 256U; i++)
	{
		for (j = 0U; j < 256U; j++)
		{
			const uint32_t distance = test_distance_mix(&MHASH_384_TABLE_MIX[i][0], &MHASH_384_TABLE_MIX[j][0]);
			if (i != j)
			{
				if (((i > j) ? (i - j) : (j - i)) == 1U)
				{
					MY_ASSERT((distance == 48U), "MIX table verification failed");
				}
				else
				{
					MY_ASSERT((distance >= 46U) && (distance <= 48U), "MIX table verification failed");
				}
			}
			else
			{
				MY_ASSERT((distance == 0U), "MIX table verification failed");
			}
		}
	}

	/*test SBX table*/
	fprintf(stderr, "Self-test, step 4 of 5 running...\n");
	for (i = 0U; i < MY_HASH_LENGTH; i++)
	{
		for (j = 0U; j < 256U; j++)
		{
			int found = 0;
			for (k = 0U; k < 256U; k++)
			{
				MY_ASSERT((MHASH_384_TABLE_SBX[k][i] !=  ((uint8_t)k)), "SBX table verification failed");
				MY_ASSERT((MHASH_384_TABLE_SBX[k][i] != ~((uint8_t)k)), "SBX table verification failed");
				if (MHASH_384_TABLE_SBX[k][i] == (uint8_t)j)
				{
					MY_ASSERT((!found), "SBX table verification failed");
					found = 1;
				}
			}
			MY_ASSERT(found, "SBX table verification failed");
		}
	}
	for (i = 0U; i < MY_HASH_LENGTH; i++)
	{
		for (j = 0U; j < MY_HASH_LENGTH; j++)
		{
			if (i != j)
			{
				MY_ASSERT(test_distance_sbx(MHASH_384_TABLE_SBX, i, j) >= 1012U, "SBX table verification failed");
			}
		}
	}

	/*test hash function*/
	fprintf(stderr, "Self-test, step 5 of 5 running...\n");
	for (i = 0; TEST_VECTOR[i].str; ++i)
	{
		fprintf(stderr, "VECTOR[%X]: ...", (unsigned int)i);
		mhash_384_initialize(&context);
		for (j = 0; j < TEST_VECTOR[i].itrations; ++j)
		{
			mhash_384_update(&context, (const uint8_t*)TEST_VECTOR[i].str, TEST_VECTOR[i].len ? TEST_VECTOR[i].len : (uint_fast32_t)strlen(TEST_VECTOR[i].str));
		}
		mhash_384_finalize(&context, result);
		fprintf(stderr, "\b\b\b");
		print_digest(stderr, result, 1, 0);
		MY_ASSERT(!memcmp(result, TEST_RESULT[i], sizeof(uint8_t) * MY_HASH_LENGTH), "Test vector did NOT compare equal");
	}

	/*completed*/
	fprintf(stderr, "Self-test completed succesfully.\n\n");
	return 0;
}

#endif /*MHASH_CLI_SELFTEST_INCLUDED*/
