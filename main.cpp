#include <iostream>
#include <bitset>
 
int main()
{
std::bitset<32> m_head_bits("11111111111111111111111111111111");
std::bitset<32> m_tail_bits("00000000000000000000000000000000");
std::bitset<32> init_bits("10000000000000000000000000000000");
size_t tail_iter_size = m_tail_bits.to_string().size();
    for (size_t bit_counter = 0; bit_counter < tail_iter_size; bit_counter += 1) {
        if (bit_counter == 0) {
            m_tail_bits |= init_bits;
            m_head_bits = m_head_bits << 1;
        } else if (bit_counter >= 1) {
            m_tail_bits = m_tail_bits >> 1; 
        }
        std::cout <<  m_head_bits << '\t' << m_tail_bits << '\n';
    }
    tail_iter_size = tail_iter_size - 1;
    std::bitset<32> tmp_bits("00000000000000000000000000000000");
    for (size_t bit_counter = 0; bit_counter < tail_iter_size; bit_counter += 1) {
        if (bit_counter == 0) {
            tmp_bits |= init_bits;
        } else if (bit_counter >= 1) {
            tmp_bits = tmp_bits >> 1; 
        }
        m_head_bits = m_head_bits << 1;
        m_tail_bits ^= tmp_bits;
        std::cout <<  m_head_bits << '\t' << m_tail_bits << '\n';
    }
}
