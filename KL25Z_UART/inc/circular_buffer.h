  #include<stdio.h>
  #include<stdint.h>

  typedef struct
  {
    uint8_t *buffer;
    uint8_t *newbuffer;
    uint8_t *head;
    uint8_t *tail;
    uint8_t size;
    uint8_t count;
  }cb;

  typedef enum
  {
    cb_init_success=0,
    cb_init_fail,
    cb_empty,
    cb_not_empty,
    cb_full,
    cb_not_full,
    null_ptr,
    buffer_NA,
    cb_success
  }buffer_status;

  buffer_status cb_init(cb *ptr, uint8_t buffer_length);
  buffer_status cb_add(cb *ptr, uint8_t element_to_add);
  buffer_status cb_delete(cb *ptr, uint8_t *element_deleted);
  buffer_status cb_isempty(cb *ptr);
  buffer_status cb_isfull(cb *ptr);
  buffer_status cb_resize(cb *ptr,uint8_t new_buffer_length);
