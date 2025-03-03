import mongoose from "mongoose";

export const dbConnection = () => {
  mongoose
    .connect("mongodb+srv://Tamim:214020@cluster0.qraxd.mongodb.net/MERN_Stack_Event_ms?retryWrites=true&w=majority", {
   
    })
    .then(() => {
      console.log("Connected to database!");
    })
    .catch((err) => {
      console.log("Some error occurred while connecting to database:", err);
    });
};