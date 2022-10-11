#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

const string chunk_id = "RIFF";
const string chunk_size = "----"; 
const string format = "WAVE";


const string chunk1_id = "fmt "; 
const int subchunk1_size = 16;
const int audio_format = 1;
const int num_channels = 2;
const int sample_rate = 44100;
const int byte_rate = sample_rate * num_channels * (subchunk1_size/8);
const int bits_per_sample = 16;


const string subchunk2_id= "data";
const string subchunk2_size = "----";

const int duration = 2;
const int max_amplitude = 32760; 
const double frequency = 250;

void write_as_bytes(ofstream &file, int value, int byte_size)
{
    file.write(reinterpret_cast<const char*>(&value), byte_size);
}

int main()
    {

        ofstream wav;
        wav.open("test.wav" , ios:: binary);

        if(wav.is_open)
    }
        {
        wav << chunk_id;
        wav << chunk_size;
        wav << format ;

        wav << subchunks1_id;
        write_as_bytes(wav, subchunk1_size,4);
        write_as_bytes(wav,audio_format,2);
        write_as_bytes(wav,num_channels,2);
        write_as_bytes(wav,sample_rate,4);
        write_as_bytes(wav,byte_rate,4);
        write_as_bytes(wav,block_align,2);
        write_as_bytes(wav,bits_per_sample,2);

        wav << subchunk2_id;
        wav << subchunk2_size;

        int start_audio = wav.tellp();
    
        for( int i =0; i < sample_rate * duration; i ++) 
            {
                double amplitude = (double)i / sample_rate *max_amplitude; 
                double value = sin((2 * 3.14 * i * frequency) / sample_rate);

                double channel1 = amplitude * value / 2;
                double channel2 = (max_amplitude - ampliude) * value;

                write_as_bytes(wav , channel1, 2);
                write_as_bytes(wav, channel2 , 2);

                int end_audio = wav.tellp();

                wav.seekp(start_audio - 4);
                write_as_bytes(wav, end_audio - start_audio, 4); 

                wav.seek(4, ios::beg);
                write_as_bytes(wav, end_audio - 8 , 4);

            }
    wav.close();
    return 0;
}








