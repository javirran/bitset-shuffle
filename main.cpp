#include <iostream>
#include <bitset>

std::bitset<32> m_head_bits("11111111111111111111111111111111");
std::bitset<32> m_tail_bits("00000000000000000000000000000000");
std::bitset<32> init_bits("10000000000000000000000000000000");
std::bitset<32> tmp_bits("00000000000000000000000000000000");
std::bitset<32> cur_bits("00000000000000000000000000000000");
std::bitset<32> prev_bits;
void addition (size_t iter_size)
{
    tmp_bits.reset();
    cur_bits = m_tail_bits;
    m_head_bits = m_head_bits << 1;
    for (size_t bit_counter = 0; bit_counter < iter_size; bit_counter += 1) {
        if (bit_counter == 0) {
            tmp_bits |= init_bits;
        } else if (bit_counter >= 1) {
            // xor with previous
            tmp_bits = tmp_bits >> 1; 
        }
        //std::cout << 't' << tmp_bits << '\n';
        m_tail_bits ^= tmp_bits;
        
        m_tail_bits ^= prev_bits;
        m_tail_bits |= cur_bits;
        
        
        std::cout <<  m_head_bits << '\t' << m_tail_bits << '\n';
        prev_bits = m_tail_bits;
    }
}

int main()
{
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
    while (tail_iter_size >= 1) {
        tail_iter_size = tail_iter_size - 1;
        addition(tail_iter_size);
    }    
}
