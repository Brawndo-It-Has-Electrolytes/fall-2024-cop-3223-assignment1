"""
/*============================================================================
| Assignment: pa01 - Calculate the checksum of an input file given:
| -> the name of the input file,
| -> the checksum size of either 8, 16, or 32 bits
| Author: Your name here
| Language: c, c++, Java, go, python, rust
| To Compile: javac pa01.java
|            gcc -o pa01 pa01.c
|            g++ -o pa01 pa01.cpp
|            go build pa01.go
|            rustc pa01.rs
| To Execute: java  -> java pa01 inputFilename.txt checksumSize
|            or c++ -> ./pa01 inputFilename.txt checksumSize
|            or c   -> ./pa01 inputFilename.txt checksumSize
|            or go  -> ./pa01 inputFilename.txt checksumSize
|            or rust-> ./pa01 inputFilename.txt checksumSize
|            or python -> python3 pa01.py inputFilename.txt checksumSize
| where inputFilename.txt is the input file
| and checksumSize is either 8, 16, or 32
| Note:
| All input files are simple 8 bit ASCII input
| All execute commands above have been tested on Eustis
| Class: CIS3360 - Security in Computing - Spring 2025
| Instructor: McAlpin
| Due Date: per assignment
+===========================================================================*/
"""
import sys


def compute_checksum(data: bytes, size: int) -> int:
    """Compute checksum of given data for specified word size."""
    # Pad with 'X' to align to word size
    word_bytes = size // 8
    if len(data) % word_bytes != 0:
        pad_len = word_bytes - (len(data) % word_bytes)
        data += b'X' * pad_len
    checksum = 0
    if size == 8:
        for b in data:
            checksum += b
    elif size == 16:
        for i in range(0, len(data), 2):
            value = (data[i] << 8) + data[i + 1]
            checksum += value
    elif size == 32:
        for i in range(0, len(data), 4):
            value = (
                (data[i] << 24)
                + (data[i + 1] << 16)
                + (data[i + 2] << 8)
                + data[i + 3]
            )
            checksum += value
    return checksum & ((1 << size) - 1)


def main():
    if len(sys.argv) != 3:
        return
    infile = sys.argv[1]
    try:
        size = int(sys.argv[2])
    except ValueError:
        print("Valid checksum sizes are 8, 16, or 32", file=sys.stderr)
        return
    if size not in (8, 16, 32):
        print("Valid checksum sizes are 8, 16, or 32", file=sys.stderr)
        return

    with open(infile, 'rb') as f:
        raw = f.read()

    # character count includes all characters, including newlines
    char_count = len(raw)

    # text for output removes newlines
    text = raw.decode('ascii')
    printable = text.replace('\n', '')
    for i in range(0, len(printable), 80):
        print(printable[i:i + 80])

    checksum = compute_checksum(raw, size)
    print(f"{size:2d} bit checksum is {checksum:8x} for all {char_count:4d} chars")


if __name__ == "__main__":
    main()

"""
/*=============================================================================
| I Your name (yourNID) affirm that this program is
| entirely my own work and that I have neither developed my code together with
| any another person, nor copied any code from any other person, nor permitted
| my code to be copied or otherwise used by any other person, nor have I
| copied, modified, or otherwise used programs created by others. I acknowledge
| that any violation of the above terms will be treated as academic dishonesty.
+=============================================================================*/
"""
