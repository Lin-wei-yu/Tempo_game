#include "Block.h"

Block::Block(int x, int y, BlockType type, ALLEGRO_BITMAP* img) {
    pos_x = x;
    pos_y = y;
    this->type = type;
    this->img = img; 
    beat_cnt = 0;
    beat_of_change = BEAT_PER_TEMPO;
    beat = false;
    if(((pos_y / GRID_SIZE) + (pos_x / GRID_SIZE)) % 2 == 0) {
        is_odd = true;
    }
    else {
        is_odd = false;
    }
}

void Block::draw() {
    if(type != BlockType::BACKGROUND) {
        if(type != BlockType::DOOR) {
            if(type == BlockType::ROAD) {
                if(is_odd) {
                    if(beat) {
                        al_draw_scaled_bitmap(img, 0, 0, GRID_SIZE, GRID_SIZE + GRID_OFFSET, pos_x, pos_y, GRID_SIZE, GRID_SIZE + GRID_OFFSET, 0);
                    }
                    else {
                        al_draw_scaled_bitmap(img, 26, 0, GRID_SIZE, GRID_SIZE + GRID_OFFSET, pos_x, pos_y, GRID_SIZE, GRID_SIZE + GRID_OFFSET, 0);
                    }
                }
                else {
                    if(beat) {
                        al_draw_scaled_bitmap(img, 26, 0, GRID_SIZE, GRID_SIZE + GRID_OFFSET, pos_x, pos_y, GRID_SIZE, GRID_SIZE + GRID_OFFSET, 0);
                    }
                    else {
                        al_draw_scaled_bitmap(img, 0, 0, GRID_SIZE, GRID_SIZE + GRID_OFFSET, pos_x, pos_y, GRID_SIZE, GRID_SIZE + GRID_OFFSET, 0);
                    }
                }
            }
            else al_draw_scaled_bitmap(img, 0, 0, GRID_SIZE, GRID_SIZE + GRID_OFFSET, pos_x, pos_y, GRID_SIZE, GRID_SIZE + GRID_OFFSET, 0);
        }
        else { // if door, put floor first then put door
            al_draw_scaled_bitmap(al_load_bitmap("assets/block/floor1.png"), 0, 0, GRID_SIZE, GRID_SIZE, pos_x, pos_y, GRID_SIZE, GRID_SIZE, 0);
            al_draw_scaled_bitmap(img, 0, 0, GRID_SIZE, GRID_SIZE + GRID_OFFSET, pos_x, pos_y, GRID_SIZE, GRID_SIZE + GRID_OFFSET, 0);
        }
    }
}

void Block::pass_beat(){
    beat_cnt++;
    if (beat_cnt == beat_of_change){
        change_animation();
        beat_cnt = 0;
    }
}
void Block::change_animation() {
    if(beat == true) {
        beat = false;
    }
    else if(beat == false){
        beat = true;
    }
}