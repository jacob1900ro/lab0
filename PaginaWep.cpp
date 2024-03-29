std::string PaginaWeb::toString()
{
  return "PaginaWeb " + std::to_string(identificador) + ", " +
         std::to_string(fecha.getDia()) + "/" + std::to_string(fecha.getMes()) + "/" + std::to_string(fecha.getAnio()) +
         ", " + this->titulo + ", " + this->link + ", " + this->texto;
};