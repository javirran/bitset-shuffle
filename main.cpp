#include <iostream>
#include <bitset>

std::bitset<32> head_bits("11111111111111111111111111111111");
std::bitset<32> tail_bits("00000000000000000000000000000000");
std::bitset<32> init_bits("10000000000000000000000000000000");
std::bitset<32> tmp_bits("00000000000000000000000000000000");
std::bitset<32> cur_bits("00000000000000000000000000000000");
std::bitset<32> prev_bits;

void step(size_t iter_size)
{
    tmp_bits.reset();
    cur_bits = tail_bits;
    // 1111 1111 -> 1111 1110 -> 1111 1100 -> ...
    head_bits = head_bits << 1;
    for (size_t bit_counter = 0; bit_counter < iter_size; bit_counter += 1) {
        if (bit_counter == 0) {
            // 1000 0000 0000 0000
            tmp_bits |= init_bits;
        } else if (bit_counter >= 1) {
            // 1000 0000 0000 0000 -> 0100 0000 0000 0000 -> 0000 0000 0001
            tmp_bits = tmp_bits >> 1; 
        }
        // 1000 0000 0000 0001 XOR 0100 0000 0000 0000 = 1100 0000 0000 0001
        tail_bits ^= tmp_bits;
        // 1100 0000 0000 0001 XOR 1000 0000 0000 0001 = 0100 0000 0000 0000
        tail_bits ^= prev_bits;
        // 0100 0000 0000 0000 OR 0000 0000 0000 0001 = 0100 0000 0000 0001
        tail_bits |= cur_bits;
        
        std::cout <<  head_bits << '\t' << tail_bits << '\n';
        prev_bits = tail_bits;
    }
}
/*
	|  head    tail   | -> |  head    tail   |
	
	1111 1111 0000 0000 -> 0000 0000 1111 1111
*/
int main()
{
    size_t tail_iter_size = tail_bits.to_string().size();
    while (tail_iter_size >= 1) {
        step(tail_iter_size);
        tail_iter_size = tail_iter_size - 1;
    }    
}
