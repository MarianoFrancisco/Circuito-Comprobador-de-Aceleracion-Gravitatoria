# Librerias que se utilizaran en el proyecto
import streamlit as st
import pandas as pd
import matplotlib.pyplot as plt

# Configuramos el tamaño de las figuras de las graficas
fig = plt.figure(figsize=(10,10))
fig.tight_layout()

st.markdown("# Aplicacion Proyecto1 Arqui1")
st.markdown("## Integrantes Grupo #2: ")
st.markdown("### Oscar Antonio de Leon Urizar - 201830498")
st.markdown("### Mariano Francisco Camposeco Camposeco - 202030987")
st.markdown("### Manuel Antonio Rojas Paxtor - 202030799")

# Se obtienen los datos del csv
datos = pd.read_csv('Files/Data45.csv', header=0);

st.markdown("## Datos Recopilados: ");
st.markdown("##### Tiempo - Velocidad: ");

# Imprimimos los datos recopilados del archivo csv
for i in range(0,datos['Tiempo'].size):
     linea = "##### " + str(datos.values[i,0])+" - "  + str(datos.values[i,1])
     st.markdown(linea)

# Se calculan los datos de velocidad, tiempo y aceleracion
velocidad = round(((datos['Velocidad'].sum()/datos['Velocidad'].size))/100,2);

tiempo = round((datos['Tiempo'].sum()/datos['Tiempo'].size),2);

aceleracion = round(((2*50)/(tiempo*tiempo))/100,2);

st.markdown("## Datos promedio: ");
st.markdown("##### Distancia: " + str(0.50) + " m");
st.markdown("##### Tiempo: " + str(tiempo) + " s");
st.markdown("##### Velocidad: " + str(velocidad) + " m/s");
st.markdown("##### Aceleracion: " + str(aceleracion) + " m/s^2");

# Se crea los datos de la primera grafica
xVel = [0,tiempo]
yVel = [0,velocidad]
gVel = plt.subplot(2,2,1);
gVel.plot(xVel, yVel, color = "blue")
gVel.set_xlabel("Tiempo")
gVel.set_ylabel("Velocidad")
gVel.set_title("Grafica Velocidad/Tiempo")
gVel.grid()
fVel = gVel.figure

# Se configura la segunda grafica
xAce = [0,tiempo]
yAce = [0,aceleracion]
gAce = plt.subplot(2,2,2);
gAce.plot(xAce, yAce, color = "red")
gAce.set_xlabel("Tiempo")
gAce.set_ylabel("Aceleracion")
gAce.set_title("Grafica Aceleracion/Tiempo")
gAce.grid()
fAce = gAce.figure

# Se configura la tercera grafica
xDis = [0,tiempo]
yDis = [0,50]
gDis = plt.subplot(2,2,3);
gDis.plot(xAce, yDis, color = "green")
gDis.set_xlabel("Tiempo")
gDis.set_ylabel("Distancia")
gDis.set_title("Grafica Distancia/Tiempo")
gDis.grid()
fDis = gDis.figure

# Se imprime la grafica
st.pyplot(fDis)
