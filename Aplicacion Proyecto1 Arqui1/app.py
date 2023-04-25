import streamlit as st
import pandas as pd
import matplotlib.pyplot as plt

fig = plt.figure(figsize=(10,10))
fig.tight_layout()

st.markdown("# Aplicacion Proyecto1 Arqui1")
st.markdown("## Integrantes Grupo #2: ")
st.markdown("### Oscar Antonio de Leon Urizar - 201830498")
st.markdown("### Mariano Francisco Camposeco Camposeco - 202030987")
st.markdown("### Manuel Antonio Rojas Paxtor - 202030799")

datos = pd.read_csv('Files/Prueba2.csv', header=0);

st.markdown("## Datos Recopilados: ");
st.markdown("##### Tiempo - Velocidad: ");

for i in range(0,datos['Tiempo'].size):
     linea = "##### " + str(datos.values[i,0])+" - "  + str(datos.values[i,1])
     st.markdown(linea)

velocidad = (datos['Velocidad'].sum()/datos['Velocidad'].size);

tiempo = (datos['Tiempo'].sum()/datos['Tiempo'].size);

aceleracion = (2*50)/(tiempo*tiempo);

st.markdown("## Datos promedio: ");
st.markdown("##### Distancia: " + str(50) + " cm");
st.markdown("##### Tiempo: " + str(tiempo) + " s");
st.markdown("##### Velocidad: " + str(velocidad) + " cm/s");
st.markdown("##### Aceleracion: " + str(aceleracion) + " cm/s^2");


xVel = [0,tiempo]
yVel = [0,velocidad]
gVel = plt.subplot(2,2,1);
gVel.plot(xVel, yVel, color = "blue")
gVel.set_xlabel("Tiempo")
gVel.set_ylabel("Velocidad")
gVel.set_title("Grafica Velocidad/Tiempo")
gVel.grid()
fVel = gVel.figure
#st.pyplot(fVel)

xAce = [0,tiempo]
yAce = [0,aceleracion]
gAce = plt.subplot(2,2,2);
gAce.plot(xAce, yAce, color = "red")
gAce.set_xlabel("Tiempo")
gAce.set_ylabel("Aceleracion")
gAce.set_title("Grafica Aceleracion/Tiempo")
gAce.grid()
fAce = gAce.figure

xDis = [0,tiempo]
yDis = [0,50]
gDis = plt.subplot(2,2,3);
gDis.plot(xAce, yDis, color = "green")
gDis.set_xlabel("Tiempo")
gDis.set_ylabel("Distancia")
gDis.set_title("Grafica Distancia/Tiempo")
gDis.grid()
fDis = gDis.figure
st.pyplot(fDis)

# plt.plot([0, tiempo], [0, velocidad]);
# plt.xlabel("Tiempo");
# plt.ylabel("Velocidad");
# plt.grid()
# plt.show()
# st.pyplot(plt)