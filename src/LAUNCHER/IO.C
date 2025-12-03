#include "IO.H"

unsigned long ReadUnsignedLE(FILE* const file, const unsigned int total_bytes)
{
	unsigned char bytes[4];
	fread(bytes, 1, total_bytes, file);

	unsigned long result = 0;
	for (unsigned int i = 0; i < total_bytes; ++i)
		result |= bytes[i] << i * 8;
	return result;
}

unsigned long ReadUnsignedBE(FILE* const file, const unsigned int total_bytes)
{
	unsigned char bytes[4];
	fread(bytes, 1, total_bytes, file);

	unsigned long result = 0;
	for (unsigned int i = 0; i < total_bytes; ++i)
	{
		result <<= 8;
		result |= bytes[i];
	}
	return result;
}

unsigned long ReadU32LE(FILE* const file)
{
	return ReadUnsignedLE(file, 4);
}

unsigned long ReadU16LE(FILE* const file)
{
	return ReadUnsignedLE(file, 2);
}

unsigned long ReadU32BE(FILE* const file)
{
	return ReadUnsignedBE(file, 4);
}

unsigned long ReadU16BE(FILE* const file)
{
	return ReadUnsignedBE(file, 2);
}

signed long ReadSigned(const unsigned long unsigned_value, const unsigned int total_bytes)
{
	const unsigned char negate = (unsigned_value >> (total_bytes * 8 - 1)) & 1;

	return (signed long)(unsigned_value ^ (0UL - negate)) + negate;
}

signed long ReadSignedLE(FILE* const file, const unsigned int total_bytes)
{
	return ReadSigned(ReadUnsignedLE(file, total_bytes), total_bytes);
}

signed long ReadS32LE(FILE* const file)
{
	return ReadSignedLE(file, 4);
}

signed long ReadS16LE(FILE* const file)
{
	return ReadSignedLE(file, 2);
}

signed long ReadSignedBE(FILE* const file, const unsigned int total_bytes)
{
	return ReadSigned(ReadUnsignedBE(file, total_bytes), total_bytes);
}

signed long ReadS32BE(FILE* const file)
{
	return ReadSignedBE(file, 4);
}

signed long ReadS16BE(FILE* const file)
{
	return ReadSignedBE(file, 2);
}
