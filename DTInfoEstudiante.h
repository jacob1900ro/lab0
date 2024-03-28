class DTInfoEstudiante
{
private:
  int cedula;
  std::string nombreEst;
  int identificadorInfo;

public:
  DTInfoEstudiante(int c, std::string nombre, int identificadorInfo) : cedula(c), nombreEst(nombre), identificadorInfo(identificadorInfo) {} // Constructor
  ~DTInfoEstudiante()
  {
    std::cout << "se borro correctamente";
  };
};