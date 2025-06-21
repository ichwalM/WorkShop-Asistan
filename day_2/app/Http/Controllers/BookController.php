<?php

namespace App\Http\Controllers;

use App\Models\Book;
use Illuminate\Http\Request;

class BookController extends Controller
{
    public function store(Request $request){
        $request->validate([
            'name' => 'required'
        ]);

        try {
            $book = new Book();
            $book->name = $request->name;
            $book->user_id=1;
            $book->save();
            
            return $this->ApiResponse("success");
        } catch (\Throwable $th) {
            return $this->ApiResponse($th->getMessage(),NULL,500);
        }
    }
}
