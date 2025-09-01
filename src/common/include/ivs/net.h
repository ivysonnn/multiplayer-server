#include <thread>
#include <vector>
#include <iostream>
#include <cstdint>
#include <ostream>
#include <type_traits>
#include <memory>

namespace ivs {
  namespace msg {
    enum class message_types : uint8_t {
      PlayerPosition,
      PlayerInput,
    };

    template <typename T>
    struct message_header {
      T id{};
      uint32_t size = 0;
    };

    template <typename T>
    struct message {
      message_header<T> header;
      std::vector<uint8_t> body;

      size_t size() const {
        return sizeof(message_header<T>) + body.size();
      }

      template <typename DataType>
      friend std::ostream& operator<< (std::ostream& os, const message<DataType>& msg) {
        os << "ID: " << int(msg.header.id) << " Size: " << msg.header.size;
        return os;
      }

      template <typename DataType>
      friend message<T>& operator<< (message<T>& msg, const DataType& data) {
        //checa se o tipo passado é simples o suficiente pra ser copiado
        static_assert(std::is_standard_layout<DataType>::value, "Data type is too complex");

        size_t i = msg.body.size();

        msg.body.resize(msg.body.size() + sizeof(DataType));

        std::memcpy(msg.body.data() + i, &data, sizeof(DataType));

        msg.header.size = msg.size();

        return msg;
      }
    };
  }

  namespace net {

  }
}