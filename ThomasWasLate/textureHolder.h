#ifndef THOMAS_WAS_LATE_TEXURE_HOLDER
#define THOMAS_WAS_LATE_TEXURE_HOLDER

#include <SFML/Graphics.hpp>
#include <map>

class TextureHolder
{
public:
   TextureHolder();
   static sf::Texture& getTexture(std::string const& filename);

private:
   std::map<std::string, sf::Texture> m_texture;

   static TextureHolder* m_s_instance;
};

#endif //THOMAS_WAS_LATE_TEXURE_HOLDER