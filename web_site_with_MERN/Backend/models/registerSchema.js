import mongoose from "mongoose";
import validator from "validator";
const registerSchema = new mongoose.Schema({
    name:{
        type: String,
        require: [true, "Name Required!"],
        minLength: [3,"Name must contain at least 3 character"],

    },
    username:{
        type: String,
        require: [true, "User Name Required!"],
        minLength: [3,"Name must contain at least 3 character"],

    },
    email: {
        type: String,
        required: [true, "Email Required!"],
        validate: [validator.isEmail, "Please provide valid email!"],
      },
      phonenumber: {
        type: String,
        require: [true, "Phone Number Required"],
        validator : [validator.isMobilePhone, "PLease provide valid Number"],
        
      },
      password: {
        type: String,
        required: [true, "Password Required!"],
        minLength: [5, "Pssword must contain at least 5 characters/Symbol/Digit!"],
      },
});
export const Register = mongoose.model("Registration", registerSchema); 