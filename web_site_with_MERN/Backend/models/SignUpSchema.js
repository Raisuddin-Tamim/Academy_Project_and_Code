import mongoose from "mongoose";
import validator from "validator";
const SignUpSchema = new mongoose.Schema({
  name: {
    type: String,
    require: [true, "Name Required!"],
    minLength: [3, "Name must contain at least 3 character"],
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
  address: {
    type: String,
    require: [true, "Address Required"],
    minLength: [3, "Name must contain at least 3 character"],
  },
  password: {
    type: String,
    required: [true, "Password Required!"],
    minLength: [5, "Pssword must contain at least 5 characters/Symbol/Digit!"],
  },
});
export const signup = mongoose.model("signup", SignUpSchema);
