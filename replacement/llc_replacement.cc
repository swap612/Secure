#include "cache.h"
#include "ooo_cpu.h"
// initialize replacement state
void CACHE::llc_initialize_replacement()
{

}

// find replacement victim
uint32_t CACHE::llc_find_victim(uint32_t cpu, uint64_t instr_id, uint32_t set, const BLOCK *current_set, uint64_t ip, uint64_t full_addr, uint32_t type)
{
    // baseline LRU
    //if(NUM_CPUS == 1)
        //return lru_victim(cpu, instr_id, set, current_set, ip, full_addr, type); 

   
    uint32_t way = 0;

    // fill invalid line first
    
    for (way = 0; way < NUM_WAY; way++)
    {
        if (block[set][way].valid == false)
        {

            DP(if (warmup_complete[cpu]) {
            cout << "[" << NAME << "] " << __func__ << " instr_id: " << instr_id << " invalid set: " << set << " way: " << way;
            cout << hex << " address: " << (full_addr>>LOG2_BLOCK_SIZE) << " victim address: " << block[set][way].address << " data: " << block[set][way].data;
            cout << dec << " lru: " << block[set][way].lru << endl; });

            return way;
        }
    }

        // LRU victim
        int cpu_max, noncpu_max, cpu_max_way, noncpu_max_way,c,flag,count,cp,flagUpper=0;
        cpu_max = -1, noncpu_max = -1, cpu_max_way = -1;
         if(way==NUM_WAY)
         {
            for (way = 0; way < NUM_WAY; way++)
            { flag=0;
              for(c=0;c<NUM_CPUS;c++)   
              {
                 if(ooo_cpu[c].L2C.search_entry(block[set][way].address)) {flag=1;}


              }
              if(flag==0)
               { 
                   flagUpper = 1;
                   if (cpu_max < block[set][way].lru)
                    {
                        cpu_max = block[set][way].lru;
                        cpu_max_way = way;
                    }
                   
               }


            }

            if(flagUpper)
                return cpu_max_way;
            
            
            for (way = 0; way < NUM_WAY; way++)
            { count=0;cp=0;
              for(c=0;c<NUM_CPUS;c++)   
              {
                 if(ooo_cpu[c].L2C.search_entry(block[set][way].address)) {count++;if(c==cpu)cp=1;}


              }
              if(count==1 && cp==1) {
                  flagUpper = 1;
                   if (cpu_max < block[set][way].lru)
                    {
                        cpu_max = block[set][way].lru;
                        cpu_max_way = way;
                    }
               
                    
                  }
            }
            
             if(flagUpper)
                return cpu_max_way;
            
           /*  for (way = 0; way < NUM_WAY; way++)
            {   
                if (cpu_max < block[set][way].lru)
                    {
                        cpu_max = block[set][way].lru;
                        cpu_max_way = way;
                    }
                    
            } 
*/

            for (way=0; way<NUM_WAY; way++) {
            if (block[set][way].lru == NUM_WAY-1) {
                cpu_max_way = way;
                DP ( if (warmup_complete[cpu]) {
                cout << "[" << NAME << "] " << __func__ << " instr_id: " << instr_id << " replace set: " << set << " way: " << way;
                cout << hex << " address: " << (full_addr>>LOG2_BLOCK_SIZE) << " victim address: " << block[set][way].address << " data: " << block[set][way].data;
                cout << dec << " lru: " << block[set][way].lru << endl; });

                break;
            }
        }
        
           
         }
        return cpu_max_way;       
        if (way == NUM_WAY)
        {
            cerr << "[" << NAME << "] " << __func__ << " no victim! set: " << set << endl;
            assert(0);
        }
        
    


}

// called on every cache hit and cache fill
void CACHE::llc_update_replacement_state(uint32_t cpu, uint32_t set, uint32_t way, uint64_t full_addr, uint64_t ip, uint64_t victim_addr, uint32_t type, uint8_t hit)
{
    string TYPE_NAME;
    if (type == LOAD)
        TYPE_NAME = "LOAD";
    else if (type == RFO)
        TYPE_NAME = "RFO";
    else if (type == PREFETCH)
        TYPE_NAME = "PF";
    else if (type == WRITEBACK)
        TYPE_NAME = "WB";
    else
        assert(0);

    if (hit)
        TYPE_NAME += "_HIT";
    else
        TYPE_NAME += "_MISS";

    if ((type == WRITEBACK) && ip)
        assert(0);

    // uncomment this line to see the LLC accesses
    // cout << "CPU: " << cpu << "  LLC " << setw(9) << TYPE_NAME << " set: " << setw(5) << set << " way: " << setw(2) << way;
    // cout << hex << " paddr: " << setw(12) << paddr << " ip: " << setw(8) << ip << " victim_addr: " << victim_addr << dec << endl;

    // baseline LRU
    if (hit && (type == WRITEBACK)) // writeback hit does not update LRU state
        return;

    return lru_update(set, way);
}

void CACHE::llc_replacement_final_stats()
{

}
