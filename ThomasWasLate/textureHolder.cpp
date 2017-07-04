#include "textureHolder.h"
#include <assert.h>

TextureHolder* TextureHolder::m_s_instance = nullptr;

TextureHolder::TextureHolder()
{
   assert(m_s_instance == nullptr);
   m_s_instance = this;
}

sf::Texture & TextureHolder::getTexture(std::string const & filename)
{
   auto& m = m_s_instance->m_texture;
   auto keyValuePair = m.find(filename);

   if (keyValuePair != m.end()) {
      return keyValuePair->second;
   }
   else {
      auto& texture = m[filename];
      texture.loadFromFile(filename);

      return texture;
   }
}